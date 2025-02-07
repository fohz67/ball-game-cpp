#include "managers/CellManager.hpp"

#include <algorithm>
#include <iostream>
#include <unordered_set>

#include "config/Config.hpp"
#include "geometry/FloatRect2.hpp"
#include "geometry/Quadtree.hpp"
#include "protocol/Send.hpp"
#include "util/AtomicID.hpp"
#include "util/Util.hpp"

CellManager& CellManager::get()
{
    static CellManager instance;
    return instance;
}

const void CellManager::generatePellets()
{
    pelletCells.clear();
    pelletCells.reserve(Config::Gameplay::Pellet::COUNT);

    for (int i = 0; i < Config::Gameplay::Pellet::COUNT; i++)
    {
        createPellet();
    }
}

const void CellManager::createPellet()
{
    uint32_t pelletId = AtomicID::get().getNextId();
    Vector2 location = Util::getRandomLocation();
    double mass = Config::Gameplay::Pellet::MASS;
    std::vector<double> color = Util::getRandomColor();

    pelletCells.emplace_back(pelletId, 0, CellType::PELLET, location, mass, color);
}

const void CellManager::generateBots()
{
    for (int i = 0; i < Config::Gameplay::Bot::COUNT; i++)
    {
        createBot();
    }
}

const void CellManager::createBot()
{
    uint32_t botId = AtomicID::get().getNextId();
    Vector2 location = Util::getRandomLocation();
    double mass = Config::Gameplay::Bot::MASS;
    std::vector<double> color = Util::getRandomColor();

    playerCells.emplace_back(botId, 0, CellType::BOT, location, mass, color);
}

const void CellManager::createCell(const uint32_t ownerId)
{
    uint32_t cellId = AtomicID::get().getNextId();
    Vector2 location = Util::getRandomLocation();
    double mass = Config::Gameplay::Cell::SPAWN_MASS;
    std::vector<double> color = Util::getRandomColor();

    playerCells.emplace_back(cellId, ownerId, CellType::PLAYER, location, mass, color);
}

const void CellManager::updateCells()
{
    std::vector<uint32_t> ids;
    size_t n = playerCells.size();

    Quadtree quadtree(
        0, FloatRect2(0, 0, Config::Gameplay::World::SIZE, Config::Gameplay::World::SIZE));

    for (Cell& cell : playerCells)
    {
        quadtree.insert(&cell);
    }

    for (size_t i = 0; i < n; i++)
    {
        Cell& cell = playerCells[i];

        if (cell.getType() != CellType::BOT)
        {
            cell.decay();
        }

        FloatRect2 cellBounds = cell.getBounds();
        std::vector<Cell*> possiblePellets = quadtree.retrieve(cellBounds);

        for (Cell* pellet : possiblePellets)
        {
            if (pellet->isMarkedForDeletion())
            {
                continue;
            }

            if (cell.canEat(*pellet))
            {
                cell.absorb(*pellet);
                pellet->markForDeletion();
                ids.push_back(pellet->getId());
            }
        }

        std::vector<Cell*> possibleTargets = quadtree.retrieve(cellBounds);

        for (Cell* target : possibleTargets)
        {
            if (cell.getId() == target->getId() || target->isMarkedForDeletion())
            {
                continue;
            }

            if (cell.canEat(*target))
            {
                cell.absorb(*target);
                target->markForDeletion();
                ids.push_back(target->getId());
            }

            if (target->canEat(cell))
            {
                target->absorb(cell);
                cell.markForDeletion();
                ids.push_back(cell.getId());
            }
        }
    }

    deleteCells(ids, 2);
}

const void CellManager::removeCells(const uint32_t ownerId)
{
    std::vector<uint32_t> ids;

    for (const Cell& cell : playerCells)
    {
        if (cell.getOwnerId() == ownerId)
        {
            ids.push_back(cell.getId());
        }
    }

    deleteCells(ids, 1);
}

const void CellManager::deleteCells(const std::vector<uint32_t>& ids, const int many)
{
    if (ids.empty())
    {
        return;
    }

    std::unordered_set<uint32_t> idSet(ids.begin(), ids.end());

    if (many > 0)
    {
        playerCells.erase(std::remove_if(playerCells.begin(),
                                         playerCells.end(),
                                         [&idSet](const Cell& cell)
                                         { return idSet.find(cell.getId()) != idSet.end(); }),
                          playerCells.end());
    }

    if (many > 1)
    {
        pelletCells.erase(std::remove_if(pelletCells.begin(),
                                         pelletCells.end(),
                                         [&idSet](const Cell& cell)
                                         { return idSet.find(cell.getId()) != idSet.end(); }),
                          pelletCells.end());
    }

    Send::sendEntityRemoved(ids);
}

std::vector<Cell*> CellManager::getPlayerCells() const
{
    std::vector<Cell*> result;

    result.reserve(playerCells.size());

    for (const Cell& cell : playerCells)
    {
        result.push_back(const_cast<Cell*>(&cell));
    }

    return result;
}

std::vector<Cell*> CellManager::getPelletCells() const
{
    std::vector<Cell*> result;

    result.reserve(pelletCells.size());

    for (const Cell& cell : pelletCells)
    {
        result.push_back(const_cast<Cell*>(&cell));
    }

    return result;
}

std::vector<Cell*> CellManager::getCellsByPlayerId(const uint32_t ownerId) const
{
    std::vector<Cell*> result;

    result.reserve(playerCells.size());

    for (const Cell& cell : playerCells)
    {
        if (cell.getType() == CellType::PLAYER && cell.getOwnerId() == ownerId)
        {
            result.push_back(const_cast<Cell*>(&cell));
        }
    }

    return result;
}
#include "managers/CellManager.hpp"
#include "config/Config.hpp"
#include "managers/PlayerManager.hpp"
#include "protocol/Protocol.hpp"
#include "protocol/Send.hpp"
#include "util/AtomicID.hpp"
#include "util/Util.hpp"

CellManager& CellManager::get() {
    static CellManager instance;
    return instance;
}

const void CellManager::generatePellets() {
    for (int i = 0; i < Config::Gameplay::Pellet::COUNT; i++) {
        const uint32_t            pelletId = AtomicID::get().getNextId();
        const Vector2             location = Util::getRandomLocation();
        const double              mass     = Config::Gameplay::Pellet::MASS;
        const std::vector<double> color    = Util::getRandomColor();

        cells.emplace_back(pelletId, pelletId, CellType::PELLET, location, mass, color);
    }
}

const void CellManager::createCell(uint32_t ownerId) {
    const Vector2             location = Util::getRandomLocation();
    const uint32_t            cellId   = AtomicID::get().getNextId();
    const double              mass     = Config::Gameplay::Cell::SPAWN_MASS;
    const std::vector<double> color    = Util::getRandomColor();

    cells.emplace_back(cellId, ownerId, CellType::PLAYER, location, mass, color);
}

const void CellManager::updateCells() {
    std::vector<uint32_t> ids;

    for (Cell& cell : cells) {
        if (cell.getType() != CellType::PLAYER) {
            continue;
        }

        cell.decay();

        for (Cell& target : cells) {
            if (cell.getId() == target.getId() || target.isMarkedForDeletion()) {
                continue;
            }

            if (cell.canEat(target)) {
                cell.absorb(target);
                target.markForDeletion();
                ids.push_back(target.getId());
            }
        }
    }

    deleteCells(ids);
}

const void CellManager::removeCells(const uint32_t ownerId) {
    std::vector<uint32_t> ids;

    for (const Cell& cell : cells) {
        if (cell.getOwnerId() == ownerId) {
            ids.push_back(cell.getId());
        }
    }

    deleteCells(ids);
}

const void CellManager::deleteCells(const std::vector<uint32_t>& ids) {
    if (ids.empty()) {
        return;
    }

    for (auto it = cells.begin(); it != cells.end();) {
        if (std::find(ids.begin(), ids.end(), it->getId()) != ids.end()) {
            it = cells.erase(it);
        } else {
            ++it;
        }
    }

    Send::sendEntityRemoved(ids);
}

std::vector<Cell*> CellManager::getCells(uint32_t ownerId) {
    std::vector<Cell*> playerCells;

    for (Cell& cell : cells) {
        if (cell.getType() == CellType::PLAYER && cell.getOwnerId() == ownerId) {
            playerCells.push_back(&cell);
        }
    }

    return playerCells;
}

std::vector<Cell>& CellManager::getAllCells() {
    return cells;
}

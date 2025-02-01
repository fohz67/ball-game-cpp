#include "managers/CellManager.hpp"
#include <cmath>
#include <random>
#include "components/Cell.hpp"
#include "config/Config.hpp"
#include "protocol/Protocol.hpp"
#include "managers/AtomicIdsManager.hpp"

CellManager& CellManager::get() {
    static CellManager instance;
    return instance;
}

std::pair<double, double> CellManager::getRandomLocation() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0, Config::GameMode::WORLD_SIZE);

    return {dis(gen), dis(gen)};
}

std::vector<double> CellManager::getRandomColor() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0, 255);

    return {dis(gen), dis(gen), dis(gen), 255};
}

void CellManager::generatePellets() {
    for (int i = 0; i < Config::GameMode::PELLET_COUNT; i++) {
        uint32_t pelletId = AtomicIdsManager::get().getNextId();
    
        CellManager::get().createCell(pelletId, CellType::PELLET);
    }
}

void CellManager::resolveEat() {
    std::lock_guard<std::mutex> lock(cellsMutex);
    std::vector<uint32_t> deletedCellsIds;

    for (auto& cell : cells) {
        if (cell.getType() != CellType::PLAYER) continue;

        for (auto& target : cells) {
            if (cell.getId() == target.getId() || target.isMarkedForDeletion()) continue;

            double dx = cell.getX() - target.getX();
            double dy = cell.getY() - target.getY();
            double distanceSquared = dx * dx + dy * dy;
            double minEatDistance = cell.getRadius() - (target.getRadius() * 0.2);

            if (cell.canEat(target) && distanceSquared < (minEatDistance * minEatDistance)) {
                cell.absorb(target);
                target.markForDeletion();
                deletedCellsIds.push_back(target.getId());
            }
        }
    }

    deleteCells(deletedCellsIds);
}

void CellManager::createCell(uint32_t ownerId, CellType type) {
    auto [spawnX, spawnY] = getRandomLocation();
    uint32_t cellId = AtomicIdsManager::get().getNextId();

    double mass = type == CellType::PLAYER   ? Config::GameMode::SPAWN_MASS
                  : type == CellType::PELLET ? Config::GameMode::PELLET_MASS
                                             : 0;
    if (!mass) {
        return;
    }

    cells.emplace_back(cellId, ownerId, type, spawnX, spawnY, mass,
                       getRandomColor());
}

void CellManager::removeCellsFromId(uint32_t ownerId) {
    std::vector<uint32_t> deletedCellsIds;

    for (const auto& cell : cells) {
        if (cell.getOwnerId() == ownerId) {
            deletedCellsIds.push_back(cell.getId());
        }
    }

    deleteCells(deletedCellsIds);
}

std::vector<Cell*> CellManager::getCellsFromId(uint32_t ownerId) {
    std::vector<Cell*> playerCells;

    for (auto& cell : cells) {
        if (cell.getType() == CellType::PLAYER &&
            cell.getOwnerId() == ownerId) {
            playerCells.push_back(&cell);
        }
    }

    return playerCells;
}

void CellManager::deleteCells(const std::vector<uint32_t>& deletedCellsIds) {
    if (deletedCellsIds.empty()) return;

    cells.erase(std::remove_if(cells.begin(), cells.end(),
                               [&deletedCellsIds](const Cell& cell) {
                                   return std::find(deletedCellsIds.begin(), deletedCellsIds.end(), cell.getId()) != deletedCellsIds.end();
                               }),
                cells.end());

    Protocol::get().sendEntityRemoved(deletedCellsIds);
}

const std::vector<Cell>& CellManager::getAllCells() const {
    return cells;
}

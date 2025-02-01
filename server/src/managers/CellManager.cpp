#include "managers/CellManager.hpp"
#include <random>
#include "config/Config.hpp"
#include "managers/AtomicIdsManager.hpp"

CellManager& CellManager::get() {
    static CellManager instance;
    return instance;
}

std::pair<double, double> CellManager::getRandomLocation() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-Config::GameMode::WORLD_SIZE / 2,
                                              Config::GameMode::WORLD_SIZE / 2);

    return {dis(gen), dis(gen)};
}

std::vector<double> CellManager::getRandomColor() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0, 255);

    return {dis(gen), dis(gen), dis(gen), 255};
}

void CellManager::createCell(uint32_t ownerId, CellType type) {
    auto [spawnX, spawnY] = getRandomLocation();
    uint32_t cellId = AtomicIdsManager::get().getNextId();

    cells.emplace_back(cellId, ownerId, type, spawnX, spawnY,
                       Config::GameMode::SPAWN_MASS, getRandomColor());
}

void CellManager::removeCellsFromId(uint32_t ownerId) {
    cells.erase(std::remove_if(cells.begin(), cells.end(),
                               [ownerId](const Cell& cell) {
                                   return cell.getOwnerId() == ownerId;
                               }),
                cells.end());
}

std::vector<Cell*> CellManager::getCellsFromId(uint32_t ownerId) {
    std::vector<Cell*> playerCells;
    for (auto& cell : cells) {
        if (cell.getOwnerId() == ownerId) {
            playerCells.push_back(&cell);
        }
    }

    return playerCells;
}

const std::vector<Cell>& CellManager::getAllCells() const {
    return cells;
}

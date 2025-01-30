#include "comps/cell/CellManager.hpp"
#include <random>
#include "Config.hpp"

CellManager& CellManager::get() {
    static CellManager instance;
    return instance;
}

void CellManager::createRandomCell(uint32_t playerId) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> disX(0, Config::World::WIDTH);
    std::uniform_real_distribution<float> disY(0, Config::World::HEIGHT);
    float spawnX = disX(gen);
    float spawnY = disY(gen);
    CellManager::get().addCell(playerId, spawnX, spawnY,
                               Config::Cell::DEFAULT_RADIUS,
                               Config::Cell::DEFAULT_SPEED);
}

void CellManager::addCell(uint32_t ownerId, float x, float y, float radius,
                          float speed) {
    cells.emplace_back(ownerId, x, y, radius, speed);
}

void CellManager::removeCellsByPlayer(uint32_t ownerId) {
    cells.erase(std::remove_if(cells.begin(), cells.end(),
                               [ownerId](const Cell& cell) {
                                   return cell.getOwnerId() == ownerId;
                               }),
                cells.end());
}

const std::vector<Cell>& CellManager::getAllCells() const {
    return cells;
}

std::vector<Cell> CellManager::getCellsByViewport(float viewportX,
                                                  float viewportY,
                                                  float viewSize) const {
    std::vector<Cell> visibleCells;
    for (const auto& cell : cells) {
        float dx = cell.getX() - viewportX;
        float dy = cell.getY() - viewportY;
        if (dx * dx + dy * dy <= viewSize * viewSize) {
            visibleCells.push_back(cell);
        }
    }
    return visibleCells;
}

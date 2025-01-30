#include "game_components/cells/CellsManager.hpp"
#include <random>
#include "GameConfig.hpp"

CellsManager& CellsManager::get() {
    static CellsManager instance;
    return instance;
}

void CellsManager::createRandomCell(uint32_t playerId) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> disX(0, GameConfig::WORLD_WIDTH);
    std::uniform_real_distribution<float> disY(0, GameConfig::WORLD_HEIGHT);
    float spawnX = disX(gen);
    float spawnY = disY(gen);
    CellsManager::get().addCell(playerId, spawnX, spawnY,
                                GameConfig::DEFAULT_CELL_RADIUS,
                                GameConfig::DEFAULT_CELL_SPEED);
}

void CellsManager::addCell(uint32_t ownerId, float x, float y, float radius,
                           float speed) {
    cells.emplace_back(ownerId, x, y, radius, speed);
}

void CellsManager::removeCellsByPlayer(uint32_t ownerId) {
    cells.erase(std::remove_if(cells.begin(), cells.end(),
                               [ownerId](const Cell& cell) {
                                   return cell.getOwnerId() == ownerId;
                               }),
                cells.end());
}

const std::vector<Cell>& CellsManager::getAllCells() const {
    return cells;
}

std::vector<Cell> CellsManager::getCellsByViewport(float viewportX,
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

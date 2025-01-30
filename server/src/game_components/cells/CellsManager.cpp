#include "game_components/cells/CellsManager.hpp"

CellsManager& CellsManager::get() {
    static CellsManager instance;
    return instance;
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

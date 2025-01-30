#include "game_components/cells/CCellsManager.hpp"

CCellsManager& CCellsManager::get() {
    static CCellsManager instance;
    return instance;
}

void CCellsManager::updateCells(const std::vector<CellData>& newCells) {
    cells = newCells;
}

const std::vector<CellData>& CCellsManager::getCells() const {
    return cells;
}

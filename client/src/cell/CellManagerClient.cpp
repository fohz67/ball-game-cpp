#include "cell/CellManagerClient.hpp"

CellManagerClient& CellManagerClient::get() {
    static CellManagerClient instance;
    return instance;
}

void CellManagerClient::updateCells(const std::vector<CellData>& newCells) {
    cells = newCells;
}

const std::vector<CellData>& CellManagerClient::getCells() const {
    return cells;
}

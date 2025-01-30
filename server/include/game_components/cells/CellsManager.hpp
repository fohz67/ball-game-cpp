#pragma once

#include <unordered_map>
#include <vector>
#include "Cell.hpp"

class CellsManager {
  public:
    CellsManager(const CellsManager&) = delete;
    CellsManager& operator=(const CellsManager&) = delete;
    static CellsManager& get();
    void addCell(uint32_t ownerId, float x, float y, float radius, float speed);
    void removeCellsByPlayer(uint32_t ownerId);
    const std::vector<Cell>& getAllCells() const;
    std::vector<Cell> getCellsByViewport(float viewportX, float viewportY,
                                         float viewSize) const;

  private:
    CellsManager() = default;
    ~CellsManager() = default;
    std::vector<Cell> cells;
};

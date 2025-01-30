#pragma once

#include <unordered_map>
#include <vector>
#include "Cell.hpp"

class CellManager {
  public:
    CellManager(const CellManager&) = delete;
    CellManager& operator=(const CellManager&) = delete;
    static CellManager& get();
    void createRandomCell(uint32_t playerId);
    void addCell(uint32_t ownerId, float x, float y, float radius, float speed);
    void removeCellsByPlayer(uint32_t ownerId);
    const std::vector<Cell>& getAllCells() const;
    std::vector<Cell> getCellsByViewport(float viewportX, float viewportY,
                                         float viewSize) const;

  private:
    CellManager() = default;
    ~CellManager() = default;
    std::vector<Cell> cells;
};

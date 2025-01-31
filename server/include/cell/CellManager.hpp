#pragma once

#include <unordered_map>
#include <vector>
#include "Cell.hpp"
#include "geometry/Quadtree.hpp"

class CellManager {
  public:
    CellManager(const CellManager&) = delete;
    CellManager& operator=(const CellManager&) = delete;
    static CellManager& get();
    void createCell(uint32_t playerId);
    void removePlayerCells(uint32_t ownerId);
    const std::vector<Cell>& getCells() const;
    std::vector<Cell*> getPlayerCells(uint32_t playerId);
    std::pair<float, float> calculateViewport(uint32_t playerId);
    void update();
    std::vector<Cell*> getNearbyCells(Cell* cell);

  private:
    CellManager();
    ~CellManager() = default;
    std::vector<Cell> cells;
    Quadtree quadtree;
};

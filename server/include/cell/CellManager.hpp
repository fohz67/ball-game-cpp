#pragma once

#include <unordered_map>
#include <vector>
#include "Cell.hpp"

class CellManager {
  public:
    CellManager(const CellManager&) = delete;
    CellManager& operator=(const CellManager&) = delete;
    static CellManager& get();
    void createCell(uint32_t playerId);
    void addCell(uint32_t ownerId, float x, float y, float radius, float speed);
    void removePlayerCells(uint32_t ownerId);
    const std::vector<Cell>& getCells() const;
    std::vector<Cell*> getPlayerCells(uint32_t playerId);
    std::pair<float, float> calculateViewport(uint32_t playerId);
    void updateCellMovement(uint32_t playerId, float mouseX, float mouseY);

  private:
    CellManager() = default;
    ~CellManager() = default;
    std::vector<Cell> cells;
};

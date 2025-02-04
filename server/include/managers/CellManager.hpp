#pragma once

#include <cstdint>
#include <vector>
#include "components/Cell.hpp"

class CellManager {
  public:
    CellManager(const CellManager&)            = delete;
    CellManager& operator=(const CellManager&) = delete;

    static CellManager& get();

    Vector2             getRandomLocation();
    std::vector<double> getRandomColor();

    void generatePellets();

    void                     createCell(uint32_t ownerId, CellType type);
    void                     updateCells();
    void                     removeCells(uint32_t ownerId);
    void                     deleteCells(const std::vector<uint32_t>& deletedIds);
    std::vector<Cell*>       getCells(uint32_t ownerId);
    const std::vector<Cell>& getAllCells() const;

  private:
    CellManager()  = default;
    ~CellManager() = default;

    std::vector<Cell> cells;
};

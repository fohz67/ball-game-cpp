#pragma once

#include <cstdint>
#include <vector>
#include "components/Cell.hpp"

class CellManager {
  public:
    CellManager(const CellManager&)            = delete;
    CellManager& operator=(const CellManager&) = delete;

    static CellManager& get();

    const void generatePellets();

    const void createCell(uint32_t ownerId);
    const void updateCells();
    const void removeCells(const uint32_t ownerId);
    const void deleteCells(const std::vector<uint32_t>& deletedIds);

    std::vector<Cell*> getCells(const uint32_t ownerId);
    std::vector<Cell>& getAllCells();

  private:
    CellManager()  = default;
    ~CellManager() = default;

    std::vector<Cell> cells;
};

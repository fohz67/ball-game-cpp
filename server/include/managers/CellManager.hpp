#pragma once

#include <cstdint>
#include <vector>
#include <mutex>
#include "components/Cell.hpp"

class CellManager {
  public:
    CellManager(const CellManager&) = delete;
    CellManager& operator=(const CellManager&) = delete;

    static CellManager& get();

    std::pair<double, double> getRandomLocation();
    std::vector<double> getRandomColor();

    void generatePellets();
    void resolveEat();

    void createCell(uint32_t ownerId, CellType type);
    void addCell(uint32_t ownerId, double x, double y, double radius,
                 double speed);

    void removeCellsFromId(uint32_t ownerId);
    std::vector<Cell*> getCellsFromId(uint32_t ownerId);
    void deleteCells(const std::vector<uint32_t>& deletedIds);
    const std::vector<Cell>& getAllCells() const;

    std::mutex cellsMutex;

  private:
    CellManager() = default;
    ~CellManager() = default;

    std::vector<Cell> cells;
};

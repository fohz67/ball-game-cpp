#pragma once

#include <cstdint>
#include <mutex>
#include <vector>
#include "components/Cell.hpp"
#include "components/Player.hpp"
#include "util/Vector2.hpp"

class CellManager {
  public:
    CellManager(const CellManager&) = delete;
    CellManager& operator=(const CellManager&) = delete;

    static CellManager& get();

    Vector2 getRandomLocation();
    std::vector<double> getRandomColor();

    void generatePellets();
    void updateCells();
    void splitCells(Player& player);
    void createCell(uint32_t ownerId, CellType type);

    std::vector<Cell*> getCellsFromId(uint32_t ownerId);
    const std::vector<Cell>& getAllCells() const;

    void removeCellsFromId(uint32_t ownerId);
    void deleteCellsFromIds(const std::vector<uint32_t>& deletedIds);

    std::mutex cellsMutex;

  private:
    CellManager() = default;
    ~CellManager() = default;

    std::vector<Cell> cells;
};

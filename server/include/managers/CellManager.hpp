#pragma once

#include <cstdint>
#include <vector>

#include "components/Cell.hpp"

class CellManager
{
   public:
    CellManager(const CellManager&) = delete;
    CellManager& operator=(const CellManager&) = delete;

    static CellManager& get();

    const void generatePellets();
    const void createPellet(const bool sendNewPellet);

    const void createCell(const uint32_t ownerId);
    const void updateCells();
    const void removeCells(const uint32_t ownerId);
    const void deleteCells(const std::vector<uint32_t>& ids, const int many);

    std::vector<Cell*> getPlayerCells() const;
    std::vector<Cell*> getPelletCells() const;
    std::vector<Cell*> getCellsByPlayerId(const uint32_t ownerId) const;

   private:
    CellManager() = default;
    ~CellManager() = default;

    std::vector<Cell> playerCells;
    std::vector<Cell> pelletCells;
};

#pragma once

#include <unordered_map>
#include <vector>
#include "CellData.hpp"

class CCellsManager {
  public:
    CCellsManager(const CCellsManager&) = delete;
    CCellsManager& operator=(const CCellsManager&) = delete;
    static CCellsManager& get();
    void updateCells(const std::vector<CellData>& newCells);
    const std::vector<CellData>& getCells() const;

  private:
    CCellsManager() = default;
    ~CCellsManager() = default;
    std::vector<CellData> cells;
};

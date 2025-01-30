#pragma once

#include <unordered_map>
#include <vector>
#include "CellData.hpp"

class CellManagerClient {
  public:
    CellManagerClient(const CellManagerClient&) = delete;
    CellManagerClient& operator=(const CellManagerClient&) = delete;
    static CellManagerClient& get();
    void updateCells(const std::vector<CellData>& newCells);
    const std::vector<CellData>& getCells() const;

  private:
    CellManagerClient() = default;
    ~CellManagerClient() = default;
    std::vector<CellData> cells;
};

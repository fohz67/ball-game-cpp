#pragma once

#include <cstdint>
#include <vector>

class PlayerClient {
  public:
    PlayerClient(uint32_t id, std::vector<double> color,
                 std::vector<double> cellColor);

    uint32_t getId() const;
    std::vector<double> getColor() const;
    std::vector<double> getCellColor() const;

  private:
    uint32_t id;
    std::vector<double> color;
    std::vector<double> cellColor;
};

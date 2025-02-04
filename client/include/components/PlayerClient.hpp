#pragma once

#include <cstdint>
#include <string>
#include <vector>

class PlayerClient {
  public:
    PlayerClient(uint32_t            id,
                 std::string         nickname,
                 std::vector<double> color,
                 std::vector<double> cellColor);

    uint32_t            getId() const;
    std::string         getNickname() const;
    std::vector<double> getColor() const;
    std::vector<double> getCellColor() const;

    void setNickname(const std::string& nickname);

  private:
    uint32_t            id;
    std::string         nickname;
    std::vector<double> color;
    std::vector<double> cellColor;
};

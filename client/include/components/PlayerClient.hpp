#pragma once

#include <cstdint>
#include <string>
#include <vector>

class PlayerClient
{
   public:
    PlayerClient(const uint32_t id,
                 const std::string nickname,
                 const std::vector<double> color,
                 const std::vector<double> cellColor);

    uint32_t getId() const;
    const std::string& getNickname() const;
    std::vector<double> getColor() const;
    std::vector<double> getCellColor() const;

    const void setNickname(const std::string& nickname);

   private:
    uint32_t id;
    std::string nickname;
    std::vector<double> color;
    std::vector<double> cellColor;
};

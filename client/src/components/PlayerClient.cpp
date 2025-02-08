#include "components/PlayerClient.hpp"

PlayerClient::PlayerClient(const uint32_t id,
                           const std::string& nickname,
                           const std::vector<double> color,
                           const std::vector<double> cellColor)
    : id(id), nickname(nickname), color(color), cellColor(cellColor)
{
}

uint32_t PlayerClient::getId() const
{
    return id;
}

const std::string& PlayerClient::getNickname() const
{
    return nickname;
}

std::vector<double> PlayerClient::getColor() const
{
    return color;
}

std::vector<double> PlayerClient::getCellColor() const
{
    return cellColor;
}

const void PlayerClient::setNickname(const std::string& nickname)
{
    this->nickname = nickname;
}

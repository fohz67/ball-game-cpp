#include "components/PlayerClient.hpp"

PlayerClient::PlayerClient(uint32_t            id,
                           std::string         nickname,
                           std::vector<double> color,
                           std::vector<double> cellColor)
    : id(id), color(color), cellColor(cellColor) {}

uint32_t PlayerClient::getId() const {
    return id;
}

std::string PlayerClient::getNickname() const {
    return nickname;
}

std::vector<double> PlayerClient::getColor() const {
    return color;
}

std::vector<double> PlayerClient::getCellColor() const {
    return cellColor;
}

long PlayerClient::getMass() const {
    return mass;
}

long PlayerClient::getScore() const {
    return score;
}

void PlayerClient::setNickname(const std::string& nickname) {
    this->nickname = nickname;
}

void PlayerClient::setMass(long newMass) {
    mass = newMass;
}

void PlayerClient::setScore(long newScore) {
    score = newScore;
}

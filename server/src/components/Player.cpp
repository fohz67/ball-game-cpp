#include "components/Player.hpp"

Player::Player(const uint32_t                                id,
               const std::shared_ptr<asio::ip::tcp::socket>& client,
               const std::vector<double>                     color,
               const std::vector<double>                     cellColor)
    : id(id), client(client), color(color), cellColor(cellColor) {}

uint32_t Player::getId() const {
    return id;
}

std::shared_ptr<asio::ip::tcp::socket> Player::getClient() const {
    return client;
}

Vector2 Player::getViewport() const {
    return viewport;
}

Vector2 Player::getMousePosition() const {
    return mousePosition;
}

std::vector<double> Player::getColor() const {
    return color;
}

std::vector<double> Player::getCellColor() const {
    return cellColor;
}

std::string Player::getNickname() const {
    return nickname;
}

double Player::getScore() const {
    return score;
}

double Player::getTotalMass() const {
    return totalMass;
}

double Player::getCellCount() const {
    return cellCount;
}

const void Player::setViewport(const Vector2& newViewport) {
    viewport = newViewport;
}

const void Player::setMousePosition(const Vector2& newMousePosition) {
    mousePosition = newMousePosition;
}

const void Player::setNickname(const std::string& newNickname) {
    nickname = newNickname;
}

const void Player::setScore(const double newScore) {
    score = newScore;
}

const void Player::setTotalMass(const double newTotalMass) {
    totalMass = newTotalMass;
}

const void Player::setCellCount(const double newCellCount) {
    cellCount = newCellCount;
}

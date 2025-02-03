#include "components/Player.hpp"

Player::Player(uint32_t id, std::shared_ptr<asio::ip::tcp::socket> client,
               std::vector<double> color, std::vector<double> cellColor)
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

void Player::setViewport(const Vector2& newViewport) {
    viewport = newViewport;
}

void Player::setMousePosition(const Vector2& newMousePosition) {
    mousePosition = newMousePosition;
}

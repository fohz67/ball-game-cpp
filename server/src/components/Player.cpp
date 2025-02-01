#include "components/Player.hpp"

Player::Player(uint32_t id, std::shared_ptr<asio::ip::tcp::socket> client)
    : id(id), client(client) {}

uint32_t Player::getId() const {
    return id;
}

std::shared_ptr<asio::ip::tcp::socket> Player::getClient() const {
    return client;
}

std::pair<double, double> Player::getViewport() const {
    return viewport;
}

std::pair<double, double> Player::getMousePosition() const {
    return mousePosition;
}

void Player::setViewport(std::pair<double, double> viewport) {
    this->viewport = viewport;
}

void Player::setMousePosition(std::pair<double, double> mousePosition) {
    this->mousePosition = mousePosition;
}

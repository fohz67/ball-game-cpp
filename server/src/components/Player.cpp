#include "components/Player.hpp"

Player::Player(uint32_t id, std::shared_ptr<asio::ip::tcp::socket> client)
    : id(id), client(client) {}

uint32_t Player::getId() const {
    return id;
}

std::shared_ptr<asio::ip::tcp::socket> Player::getClient() const {
    return client;
}

Point Player::getViewport() const {
    return viewport;
}

Point Player::getMousePosition() const {
    return mousePosition;
}

void Player::setViewport(Point viewport) {
    this->viewport = viewport;
}

void Player::setMousePosition(Point mousePosition) {
    this->mousePosition = mousePosition;
}

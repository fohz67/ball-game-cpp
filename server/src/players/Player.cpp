#include "players/Player.hpp"

Player::Player(uint32_t id, std::shared_ptr<asio::ip::tcp::socket> client)
    : id(id), client(client), viewportX(500), viewportY(500) {}

uint32_t Player::getId() const {
    return id;
}

std::shared_ptr<asio::ip::tcp::socket> Player::getClient() const {
    return client;
}

std::pair<float, float> Player::getViewport() const {
    return {viewportX, viewportY};
}

void Player::setViewport(float x, float y) {
    viewportX = x;
    viewportY = y;
}

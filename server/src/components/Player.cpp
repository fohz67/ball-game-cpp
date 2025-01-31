#include "components/Player.hpp"

Player::Player(uint32_t id, std::shared_ptr<asio::ip::tcp::socket> client)
    : id(id), client(client) {}

uint32_t Player::getId() const {
    return id;
}

std::shared_ptr<asio::ip::tcp::socket> Player::getClient() const {
    return client;
}

Viewport Player::getViewport() const {
    return viewport;
}

MousePosition Player::getMousePosition() const {
    return mousePosition;
}

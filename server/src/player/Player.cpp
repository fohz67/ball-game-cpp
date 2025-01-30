#include "player/Player.hpp"

Player::Player(uint32_t id, std::shared_ptr<asio::ip::tcp::socket> client)
    : id(id), client(client), viewportX(500), viewportY(500), mouseX(0.5), mouseY(0.5) {}

uint32_t Player::getId() const {
    return id;
}

std::shared_ptr<asio::ip::tcp::socket> Player::getClient() const {
    return client;
}

std::pair<float, float> Player::getViewport() const {
    return {viewportX, viewportY};
}

float Player::getViewportX() const {
    return viewportX;
}

float Player::getViewportY() const {
    return viewportY;
}

void Player::setViewport(float x, float y) {
    viewportX = x;
    viewportY = y;
}

std::pair<float, float> Player::getMousePosition() const {
    return {mouseX, mouseY};
}

float Player::getMouseX() const {
    return mouseX;
}

float Player::getMouseY() const {
    return mouseY;
}

void Player::setMousePosition(float x, float y) {
    mouseX = x;
    mouseY = y;
}

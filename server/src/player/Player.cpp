#include "player/Player.hpp"

Player::Player(uint32_t id, std::shared_ptr<asio::ip::tcp::socket> client)
    : id(id), client(client), viewportX(0), viewportY(0), mouseX(0),
      mouseY(0) {}

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

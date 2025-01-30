#include "game_components/cells/Cell.hpp"

Cell::Cell(uint32_t ownerId, float x, float y, float radius, float speed)
    : ownerId(ownerId), x(x), y(y), radius(radius), speed(speed) {}

uint32_t Cell::getOwnerId() const {
    return ownerId;
}

float Cell::getX() const {
    return x;
}

float Cell::getY() const {
    return y;
}

float Cell::getRadius() const {
    return radius;
}

float Cell::getSpeed() const {
    return speed;
}

void Cell::setPosition(float x, float y) {
    this->x = x;
    this->y = y;
}

void Cell::setRadius(float radius) {
    this->radius = radius;
}

void Cell::setSpeed(float speed) {
    this->speed = speed;
}

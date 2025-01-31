#include "cell/Cell.hpp"
#include <cmath>

Cell::Cell(uint32_t ownerId, float x, float y, float radius)
    : ownerId(ownerId), position(x, y), velocity(0, 0), radius(radius),
      markedForDeletion(false), age(0) {}

uint32_t Cell::getOwnerId() const {
    return ownerId;
}

Vector2 Cell::getPosition() const {
    return position;
}

void Cell::setPosition(const Vector2& pos) {
    position = pos;
}

Vector2 Cell::getVelocity() const {
    return velocity;
}

void Cell::setVelocity(const Vector2& vel) {
    velocity = vel;
}

float Cell::getRadius() const {
    return radius;
}

void Cell::setRadius(float r) {
    radius = r;
}

float Cell::getMass() const {
    return radius * radius * M_PI;
}

bool Cell::isMarkedForDeletion() const {
    return markedForDeletion;
}

void Cell::markForDeletion() {
    markedForDeletion = true;
}

float Cell::getAge() const {
    return age;
}

void Cell::update(float deltaTime) {
    position += velocity * deltaTime;
}

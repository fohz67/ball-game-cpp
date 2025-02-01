#include "components/Cell.hpp"
#include <algorithm>

Cell::Cell(uint32_t id, uint32_t ownerId, CellType type, double x, double y,
           double mass, std::vector<double> color)
    : id(id), ownerId(ownerId), type(type), x(x), y(y), mass(mass),
      color(color) {}

uint32_t Cell::getId() const {
    return id;
}

uint32_t Cell::getOwnerId() const {
    return ownerId;
}

CellType Cell::getType() const {
    return type;
}

double Cell::getX() const {
    return x;
}

double Cell::getY() const {
    return y;
}

double Cell::getMass() const {
    return mass;
}

double Cell::getRadius() const {
    return std::sqrt(mass / M_PI);
}

std::vector<double> Cell::getColor() const {
    return color;
}

void Cell::setPosition(double x, double y) {
    this->x = x;
    this->y = y;
}

void Cell::setMass(double mass) {
    this->mass = mass;
}

void Cell::move(double dirX, double dirY, double speed, double worldSize) {
    double newX = getX() + dirX * speed;
    double newY = getY() + dirY * speed;

    double minX = 0;
    double minY = 0;
    double maxX = worldSize - getRadius();
    double maxY = worldSize - getRadius();

    newX = std::max(minX, std::min(maxX, newX));
    newY = std::max(minY, std::min(maxY, newY));

    setPosition(newX, newY);
}

void Cell::resolveCollision(Cell& other) {
    double dx = getX() - other.getX();
    double dy = getY() - other.getY();
    double distance = std::sqrt(dx * dx + dy * dy);
    double minDist = getRadius() + other.getRadius();

    if (distance < minDist && distance > 0) {
        double overlap = minDist - distance;
        double adjustX = (dx / distance) * overlap * 0.5;
        double adjustY = (dy / distance) * overlap * 0.5;

        setPosition(getX() + adjustX, getY() + adjustY);
        other.setPosition(other.getX() - adjustX, other.getY() - adjustY);
    }
}

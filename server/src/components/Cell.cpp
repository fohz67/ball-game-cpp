#include "components/Cell.hpp"
#include <algorithm>
#include "geometry/FastInvSqrt.hpp"

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
    return mass * fastInvSqrt(M_PI * mass);
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

bool Cell::canEat(const Cell& other) const {
    if (mass < other.mass * 1.1) {
        return false;
    }

    double dx = x - other.x;
    double dy = y - other.y;
    double distanceSquared = dx * dx + dy * dy;

    return distanceSquared < (mass - other.mass) * (mass - other.mass);
}

void Cell::absorb(Cell& other) {
    mass += other.getMass();
}

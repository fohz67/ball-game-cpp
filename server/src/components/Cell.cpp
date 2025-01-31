#include "components/Cell.hpp"

Cell::Cell(uint32_t ownerId, CellType type, double x, double y, double radius,
           std::vector<double> color)
    : ownerId(ownerId), type(type), x(x), y(y), radius(radius), color(color) {}

uint32_t Cell::getOwnerId() const {
    return ownerId;
}

double Cell::getX() const {
    return x;
}

double Cell::getY() const {
    return y;
}

double Cell::getRadius() const {
    return radius;
}

void Cell::setPosition(double x, double y) {
    this->x = x;
    this->y = y;
}

void Cell::setRadius(double radius) {
    this->radius = radius;
}

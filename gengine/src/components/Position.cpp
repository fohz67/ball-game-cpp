#include "components/Position.hpp"
#include <iostream>

Position::Position(const std::vector<Point>& positions)
    : positions(positions) {}

std::vector<Point> Position::getPositions() const {
    return positions;
}

double Position::getPositionX(const uint32_t id) const {
    return this->positions[id].first;
}

double Position::getPositionY(const uint32_t id) const {
    return this->positions[id].second;
}

void Position::setPositionX(const uint32_t id, const double x) {
    this->positions[id].first = x;
}

void Position::setPositionY(const uint32_t id, const double y) {
    this->positions[id].second = y;
}

void Position::addPosition(const double x, const double y) {
    this->positions.emplace_back(x, y);
}

void Position::removePosition(const uint32_t id) {
    this->positions.erase(this->positions.begin() + id);
}

void Position::display() const {
    std::cout << "Position component displayed!" << std::endl;
}

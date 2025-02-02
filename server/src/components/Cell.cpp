#include "components/Cell.hpp"
#include "components/World.hpp"
#include "config/Config.hpp"
#include "geometry/FastInvSqrt.hpp"

Cell::Cell(uint32_t id, uint32_t ownerId, CellType type, Point pos, double mass,
           std::vector<double> color)
    : id(id), ownerId(ownerId), type(type), pos(pos), mass(mass), color(color) {
}

uint32_t Cell::getId() const {
    return id;
}

uint32_t Cell::getOwnerId() const {
    return ownerId;
}

CellType Cell::getType() const {
    return type;
}

Point Cell::getPosition() const {
    return pos;
}

double Cell::getMass() const {
    return mass;
}

double Cell::getRadius() const {
    return Config::Gameplay::Cell::RADIUS_FACTOR * (mass * FIS(M_PI * mass));
}

Point Cell::getCenter() const {
    return {pos.first + getRadius(), pos.second + getRadius()};
}

std::vector<double> Cell::getColor() const {
    return color;
}

void Cell::setPosition(Point newPos) {
    pos = newPos;
}

void Cell::setMass(double mass) {
    this->mass = mass;
}

void Cell::decay() {
    if (decayResolver < Config::Gameplay::Cell::DECAY_TIMING) {
        decayResolver += Config::Game::FREQUENCY;
        return;
    }

    decayResolver = 0;
    mass -= mass * Config::Gameplay::Cell::DECAY_RATE;
}

void Cell::move(Point dir, double speed) {
    Point newPos = {pos.first + dir.first * speed,
                    pos.second + dir.second * speed};
    std::vector<double> boundaries = World::getWorldBoundaries();

    newPos.first = std::max(
        boundaries[0], std::min(boundaries[1] - getRadius() * 2, newPos.first));
    newPos.second =
        std::max(boundaries[2],
                 std::min(boundaries[3] - getRadius() * 2, newPos.second));

    setPosition(newPos);
}

bool Cell::canEat(const Cell& other) const {
    if (mass < other.mass * Config::Gameplay::Eat::Eat::RESOLVE_FACTOR) {
        return false;
    }

    Point cellCenter = getCenter();
    Point otherCellCenter = other.getCenter();
    Point diff = {cellCenter.first - otherCellCenter.first,
                  cellCenter.second - otherCellCenter.second};

    double distanceSquared =
        diff.first * diff.first + diff.second * diff.second;
    double minEatDistance =
        getRadius() -
        (other.getRadius() * Config::Gameplay::Eat::Eat::RESOLVE_OVERLAP);
    double minEatDistanceSquared = minEatDistance * minEatDistance;

    return distanceSquared < minEatDistanceSquared;
}

void Cell::absorb(Cell& other) {
    double oldRadius = getRadius();

    if (other.type == CellType::PELLET) {
        mass += (other.getMass() * Config::Gameplay::Pellet::EAT_FACTOR);
    } else {
        mass += other.getMass();
    }

    double deltaRadius = getRadius() - oldRadius;

    pos = {pos.first - deltaRadius / 2.0, pos.second - deltaRadius / 2.0};
}

void Cell::markForDeletion() {
    markedForDeletion = true;
}

bool Cell::isMarkedForDeletion() const {
    return markedForDeletion;
}

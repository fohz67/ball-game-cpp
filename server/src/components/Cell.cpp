#include "components/Cell.hpp"
#include "components/World.hpp"
#include "config/Config.hpp"
#include "geometry/FastInvSqrt.hpp"

Cell::Cell(uint32_t id, uint32_t ownerId, CellType type, Vector2& pos,
           double mass, std::vector<double> color)
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

Vector2 Cell::getPosition() const {
    return pos;
}

double Cell::getMass() const {
    return mass;
}

double Cell::getRadius() const {
    return mass * FIS(M_PI * mass);
}

Vector2 Cell::getCenter() const {
    return Vector2(pos.x + getRadius(), pos.y + getRadius());
}

std::vector<double> Cell::getColor() const {
    return color;
}

void Cell::setPosition(const Vector2& newPos) {
    pos = newPos;
}

void Cell::setMass(const double mass) {
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

void Cell::move(const Vector2& dir, const double speed) {
    Vector2 newPos(pos + dir * speed);
    std::vector<double> boundaries = World::getWorldBoundaries();
    double limitRadius = getRadius() * 2;

    newPos.x = std::max(boundaries[0],
                        std::min(boundaries[1] - limitRadius, newPos.x));
    newPos.y = std::max(boundaries[2],
                        std::min(boundaries[3] - limitRadius, newPos.y));
    pos = newPos;
}

bool Cell::canEat(const Cell& other) const {
    if (mass < other.mass * Config::Gameplay::Eat::Eat::RESOLVE_FACTOR) {
        return false;
    }

    Vector2 diff(getCenter() - other.getCenter());
    double distanceSquared = diff.dot(diff);
    double minEatDistance =
        getRadius() -
        (other.getRadius() * Config::Gameplay::Eat::Eat::RESOLVE_OVERLAP);

    return distanceSquared < minEatDistance * minEatDistance;
}

void Cell::absorb(const Cell& other) {
    double oldRadius = getRadius();

    if (other.type == CellType::PELLET) {
        mass += (other.getMass() * Config::Gameplay::Pellet::EAT_FACTOR);
    } else {
        mass += other.getMass();
    }

    pos -= (getRadius() - oldRadius) / 2.0;
}

void Cell::markForDeletion() {
    markedForDeletion = true;
}

bool Cell::isMarkedForDeletion() const {
    return markedForDeletion;
}

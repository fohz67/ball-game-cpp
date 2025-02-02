#include "components/Cell.hpp"
#include "components/World.hpp"
#include "config/Config.hpp"
#include "util/FastInvSqrt.hpp"

Cell::Cell(uint32_t id, uint32_t ownerId, CellType type, const Vector2& pos,
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

Vector2 Cell::getBoost() const {
    return boost;
}

Vector2 Cell::getVelocity() const {
    return velocity;
}

double Cell::getMass() const {
    return mass;
}

double Cell::getRadius() const {
    return Config::Gameplay::Cell::RADIUS_FACTOR *
           (mass * FIS(M_PI * mass));
}

Vector2 Cell::getCenter() const {
    return pos + Vector2(getRadius(), getRadius());
}

std::vector<double> Cell::getColor() const {
    return color;
}

void Cell::setPosition(const Vector2& newPos) {
    pos = newPos;
}

void Cell::setBoost(const Vector2& newBoost) {
    boost = newBoost;
}

void Cell::setVelocity(const Vector2& newVelocity) {
    velocity = newVelocity;
}

void Cell::setMass(double newMass) {
    mass = newMass;
}

void Cell::decay() {
    if (decayResolver < Config::Gameplay::Cell::DECAY_TIMING) {
        decayResolver += Config::Game::FREQUENCY;
        return;
    }

    decayResolver = 0;
    mass -= mass * Config::Gameplay::Cell::DECAY_RATE;
}

void Cell::move(const Vector2& dir, double speed) {
    Vector2 newPos = pos + dir * speed;
    std::vector<double> boundaries = World::getWorldBoundaries();

    newPos.x = std::max(boundaries[0],
                        std::min(boundaries[1] - getRadius() * 2, newPos.x));
    newPos.y = std::max(boundaries[2],
                        std::min(boundaries[3] - getRadius() * 2, newPos.y));
    pos = newPos;
}

bool Cell::canEat(const Cell& other) const {
    if (mass < other.mass * Config::Gameplay::Eat::Eat::RESOLVE_FACTOR) {
        return false;
    }

    double minEatDistance =
        getRadius() -
        (other.getRadius() * Config::Gameplay::Eat::Eat::RESOLVE_OVERLAP);
    double minEatDistanceSquared = minEatDistance * minEatDistance;

    Vector2 diff = getCenter() - other.getCenter();

    return diff.x * diff.x + diff.y * diff.y < minEatDistanceSquared;
}

void Cell::absorb(Cell& other) {
    double oldRadius = getRadius();

    if (other.getType() == CellType::PELLET) {
        mass += (other.getMass() * Config::Gameplay::Pellet::EAT_FACTOR);
    } else {
        mass += other.getMass();
    }

    double deltaRadius = getRadius() - oldRadius;
    pos = pos - Vector2(deltaRadius / 2.0, deltaRadius / 2.0);
}

void Cell::stepMotion() {
    pos = pos + velocity + boost; boost = boost * Config::Gameplay::World::FRICTION;
}

void Cell::markForDeletion() {
    markedForDeletion = true;
}

bool Cell::isMarkedForDeletion() const {
    return markedForDeletion;
}

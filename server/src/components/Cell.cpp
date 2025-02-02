#include "components/Cell.hpp"
#include "config/Config.hpp"
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
    return Config::Gameplay::Cell::RADIUS_FACTOR * (mass * FIS(M_PI * mass));
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

void Cell::decay() {
    if (this->decayResolver < 1000) {
        this->decayResolver += Config::Game::FREQUENCY;
        return;
    }

    this->decayResolver = 0;
    this->mass -= mass * Config::Gameplay::Cell::DECAY_RATE;
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
    if (mass < other.mass * Config::Gameplay::Eat::Eat::RESOLVE_FACTOR) {
        return false;
    }

    double dx = x - other.x;
    double dy = y - other.y;
    double distanceSquared = dx * dx + dy * dy;

    return distanceSquared < (mass - other.mass) * (mass - other.mass);
}

void Cell::absorb(Cell& other) {
    if (other.type == CellType::PELLET) {
        mass += (other.getMass() * Config::Gameplay::Pellet::EAT_FACTOR);
        return;
    }

    mass += other.getMass();
}

void Cell::markForDeletion() {
    markedForDeletion = true;
}

bool Cell::isMarkedForDeletion() const {
    return markedForDeletion;
}

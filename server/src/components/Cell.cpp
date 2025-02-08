#include "components/Cell.hpp"

#include "components/World.hpp"
#include "config/Config.hpp"
#include "geometry/FastInvSqrt.hpp"

Cell::Cell(const uint32_t id,
           const uint32_t ownerId,
           const CellType type,
           const Vector2& pos,
           const double mass,
           const std::vector<double> color)
    : id(id), ownerId(ownerId), type(type), pos(pos), mass(mass), color(color)
{
}

uint32_t Cell::getId() const
{
    return id;
}

uint32_t Cell::getOwnerId() const
{
    return ownerId;
}

CellType Cell::getType() const
{
    return type;
}

Vector2 Cell::getPosition() const
{
    return pos;
}

double Cell::getMass() const
{
    return mass;
}

double Cell::getRadius() const
{
    return mass * FIS(M_PI * mass);
}

Vector2 Cell::getCenter() const
{
    return Vector2(pos.x + getRadius(), pos.y + getRadius());
}

std::vector<double> Cell::getColor() const
{
    return color;
}

FloatRect2 Cell::getBounds() const
{
    return FloatRect2(pos.x, pos.y, getRadius() * 2, getRadius() * 2);
}

void Cell::setPosition(const Vector2& newPos)
{
    pos = newPos;
}

void Cell::setMass(const double mass)
{
    this->mass = mass;
}

void Cell::decay()
{
    mass -= mass * Config::Gameplay::Cell::DECAY_RATE;
}

void Cell::move(const Vector2& dir, const double speed)
{
    Vector2 newPos(pos + dir * speed);
    const std::vector<double> boundaries = World::getWorldBoundaries();
    const double limitRadius = getRadius() * 2;

    newPos.x = std::max(boundaries[0], std::min(boundaries[1] - limitRadius, newPos.x));
    newPos.y = std::max(boundaries[2], std::min(boundaries[3] - limitRadius, newPos.y));
    pos = newPos;
}

bool Cell::canEat(const Cell& other) const
{
    if (mass < other.mass * Config::Gameplay::Eat::Eat::RESOLVE_FACTOR)
    {
        return false;
    }

    Vector2 diff(getCenter() - other.getCenter());
    const double distanceSquared = diff.dot(diff);
    const double minEatDistance =
        getRadius() - (other.getRadius() * Config::Gameplay::Eat::Eat::RESOLVE_OVERLAP);

    return distanceSquared < minEatDistance * minEatDistance;
}

void Cell::absorb(const Cell& other)
{
    const double oldRadius = getRadius();

    if (other.type == CellType::PELLET)
    {
        mass += (other.getMass() * Config::Gameplay::Pellet::EAT_FACTOR);
    }
    else
    {
        mass += other.getMass();
    }

    pos -= (getRadius() - oldRadius) / 2.0;
}

void Cell::markForDeletion()
{
    markedForDeletion = true;
}

bool Cell::isMarkedForDeletion() const
{
    return markedForDeletion;
}

#include "components/Position.hpp"

#include <iostream>

Position::Position(const Point& position)
    : position(position), previousPosition(position), targetPosition(position)
{
}

Point Position::getPosition() const
{
    return position;
}
Point Position::getInterpolatedPosition(float dt)
{
    interpolationFactor += dt * interpolationSpeed;

    if (interpolationFactor > 1.0f)
    {
        interpolationFactor = 1.0f;
    }

    float t = interpolationFactor;
    t = t * t * (3 - 2 * t);

    return {previousPosition.first + (targetPosition.first - previousPosition.first) * t,
            previousPosition.second + (targetPosition.second - previousPosition.second) * t};
}

double Position::getPositionX() const
{
    return position.first;
}

double Position::getPositionY() const
{
    return position.second;
}

void Position::setPosition(const Point& pos)
{
    if (std::fabs(targetPosition.first - pos.first) > 0.01 ||
        std::fabs(targetPosition.second - pos.second) > 0.01)
    {
        previousPosition = getInterpolatedPosition(1.0f);
        targetPosition = pos;
        interpolationFactor = 0.0f;
    }
}

void Position::setPositionX(double x)
{
    if (position.first != x)
    {
        previousPosition.first = position.first;
        targetPosition.first = x;
        interpolationFactor = 0.0f;
    }
}

void Position::setPositionY(double y)
{
    if (position.second != y)
    {
        previousPosition.second = position.second;
        targetPosition.second = y;
        interpolationFactor = 0.0f;
    }
}

void Position::display() const
{
    std::cout << "Position: (" << position.first << ", " << position.second << ")" << std::endl;
}

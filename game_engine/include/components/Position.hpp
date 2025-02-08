#pragma once

#include <cstdint>
#include <utility>
#include <vector>

#include "components/Components.hpp"
#include "components/Point.hpp"

class Position : public Component
{
   public:
    // Constants
    static inline Point DEFAULT_POSITION = {0.0f, 0.0f};

    // Constructor / Destructor
    Position(const Point& positions = DEFAULT_POSITION);
    ~Position() = default;

    // Getters
    Point getPosition() const;
    Point getInterpolatedPosition(float dt);
    double getPositionX() const;
    double getPositionY() const;

    // Setters
    void setPosition(const Point& pos);
    void setPositionX(const double x);
    void setPositionY(const double y);

    // Methods
    void display() const override;

   private:
    // Attributes
    Point position;
    Point previousPosition;
    Point targetPosition;

    float interpolationFactor = 0.0f;
    float interpolationSpeed = 15.0f;
};

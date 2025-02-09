#pragma once

#include <cstdint>
#include <utility>
#include <vector>

#include "geometry/FloatRect2.hpp"
#include "geometry/Vector2.hpp"

enum CellType
{
    PLAYER,
    PELLET,
    BOT
};

class Cell
{
   public:
    Cell(const uint32_t id,
         const uint32_t ownerId,
         const CellType type,
         const Vector2& pos,
         const double mass,
         const std::vector<double> color);

    uint32_t getId() const;
    uint32_t getOwnerId() const;
    CellType getType() const;
    Vector2 getPosition() const;
    double getMass() const;
    double getRadius() const;
    Vector2 getCenter() const;
    std::vector<double> getColor() const;
    FloatRect2 getBounds() const;

    void setPosition(const Vector2& newPos);
    void setMass(const double mass);

    void decay();
    void move(const Vector2& dir, const double speed);
    bool canEat(const Cell& other) const;
    void absorb(const Cell& other);

    void markForDeletion();
    bool isMarkedForDeletion() const;

   private:
    uint32_t id;
    uint32_t ownerId;
    CellType type;
    Vector2 pos;
    double mass;
    std::vector<double> color;
    double speed;
    bool markedForDeletion = false;
};

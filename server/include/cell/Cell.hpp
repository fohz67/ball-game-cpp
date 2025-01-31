#pragma once

#include "geometry/Vector2.hpp"
#include <cstdint>

class Cell {
protected:
    uint32_t ownerId;
    Vector2 position;
    Vector2 velocity;
    float radius;
    bool markedForDeletion;
    float age;

public:
    Cell(uint32_t ownerId, float x, float y, float radius);
    
    uint32_t getOwnerId() const;
    Vector2 getPosition() const;
    void setPosition(const Vector2& pos);

    Vector2 getVelocity() const;
    void setVelocity(const Vector2& vel);

    float getRadius() const;
    void setRadius(float r);

    float getMass() const;
    bool isMarkedForDeletion() const;
    void markForDeletion();

    void update(float deltaTime);
    float getAge() const;
};

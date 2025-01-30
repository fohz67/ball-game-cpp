#pragma once

#include <cstdint>

class Cell {
  public:
    Cell(uint32_t ownerId, float x, float y, float radius, float speed);
    uint32_t getOwnerId() const;
    float getX() const;
    float getY() const;
    float getRadius() const;
    float getSpeed() const;
    void setPosition(float x, float y);
    void setRadius(float radius);
    void setSpeed(float speed);

  private:
    uint32_t ownerId;
    float x, y;
    float radius;
    float speed;
};

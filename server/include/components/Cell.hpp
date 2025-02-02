#pragma once

#include <cstdint>
#include <utility>
#include <vector>
#include "util/Vector2.hpp"

enum CellType { PLAYER, DEAD, EJECTED, PELLET };

class Cell {
  public:
    Cell(uint32_t id, uint32_t ownerId, CellType type, const Vector2& pos,
         double mass, std::vector<double> color);

    uint32_t getId() const;
    uint32_t getOwnerId() const;
    CellType getType() const;
    Vector2 getPosition() const;
    Vector2 getBoost() const;
    Vector2 getVelocity() const;
    double getMass() const;
    double getRadius() const;
    Vector2 getCenter() const;
    std::vector<double> getColor() const;

    void setPosition(const Vector2& newPos);
    void setBoost(const Vector2& newBoost);
    void setVelocity(const Vector2& newVelocity);
    void setMass(double newMass);

    void decay();
    void move(const Vector2& dir, double speed);
    bool canEat(const Cell& other) const;
    void absorb(Cell& other);
    void stepMotion();

    void markForDeletion();
    bool isMarkedForDeletion() const;

  private:
    uint32_t id;
    uint32_t ownerId;
    CellType type;
    Vector2 pos;
    Vector2 boost;
    Vector2 velocity;
    double mass;
    std::vector<double> color;
    double speed;
    bool markedForDeletion = false;
    int decayResolver = 0;
};

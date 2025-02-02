#pragma once

#include <cstdint>
#include <utility>
#include <vector>
#include "components/Point.hpp"

enum CellType { PLAYER, DEAD, EJECTED, PELLET };

class Cell {
  public:
    Cell(uint32_t id, uint32_t ownerId, CellType type, Point pos, double mass,
         std::vector<double> color);

    uint32_t getId() const;
    uint32_t getOwnerId() const;
    CellType getType() const;
    Point getPosition() const;
    double getMass() const;
    double getRadius() const;
    Point getCenter() const;
    std::vector<double> getColor() const;

    void setPosition(Point newPos);
    void setMass(double mass);

    void decay();

    void move(Point dir, double speed);
    bool canEat(const Cell& other) const;
    void absorb(Cell& other);

    void markForDeletion();
    bool isMarkedForDeletion() const;

  private:
    uint32_t id;
    uint32_t ownerId;
    CellType type;
    Point pos;
    double mass;
    std::vector<double> color;
    double speed;
    bool markedForDeletion = false;
    int decayResolver = 0;
};

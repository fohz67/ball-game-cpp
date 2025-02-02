#pragma once

#include <cstdint>
#include <vector>

enum CellType { PLAYER, DEAD, EJECTED, PELLET };

class Cell {
  public:
    Cell(uint32_t id, uint32_t ownerId, CellType type, double x, double y,
         double mass, std::vector<double> color);

    uint32_t getId() const;
    uint32_t getOwnerId() const;
    CellType getType() const;
    double getX() const;
    double getY() const;
    double getMass() const;
    double getRadius() const;
    std::vector<double> getColor() const;

    void setPosition(double x, double y);
    void setMass(double mass);

    void decay();

    void move(double dirX, double dirY, double speed, double worldSize);
    bool canEat(const Cell& other) const;
    void absorb(Cell& other);

    void markForDeletion();
    bool isMarkedForDeletion() const;

  private:
    uint32_t id;
    uint32_t ownerId;
    CellType type;
    double x;
    double y;
    double mass;
    std::vector<double> color;
    double speed;
    bool markedForDeletion = false;
    int decayResolver = 0;
};

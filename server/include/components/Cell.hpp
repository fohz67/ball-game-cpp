#pragma once

#include <cstdint>
#include <vector>

enum CellType { PLAYER, DEAD, EJECTED, PELLET };

class Cell {
  public:
    Cell(uint32_t id, uint32_t ownerId, CellType type, double x, double y,
         double radius, std::vector<double> color);

    uint32_t getId() const;
    uint32_t getOwnerId() const;
    CellType getType() const;
    double getX() const;
    double getY() const;
    double getRadius() const;
    std::vector<double> getColor() const;

    void setPosition(double x, double y);
    void setRadius(double radius);

  private:
    uint32_t id;
    uint32_t ownerId;
    CellType type;
    double x;
    double y;
    double radius;
    std::vector<double> color;
    double speed;
};

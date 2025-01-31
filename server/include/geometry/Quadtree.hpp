#pragma once

#include <vector>
#include "cell/Cell.hpp"

class Quadtree {
  public:
    Quadtree(float x, float y, float width, float height, int level = 0,
             int maxObjects = 10);
    void insert(Cell* cell);
    std::vector<Cell*> retrieve(Cell* cell);
    void clear();

  private:
    float x, y, width, height;
    int level;
    int maxObjects;
    std::vector<Cell*> objects;
    bool divided;
    Quadtree* topLeft;
    Quadtree* topRight;
    Quadtree* bottomLeft;
    Quadtree* bottomRight;
    void subdivide();
    bool contains(Cell* cell);
};

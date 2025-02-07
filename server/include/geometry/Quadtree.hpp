#pragma once

#include <vector>

#include "./components/Cell.hpp"
#include "./geometry/FloatRect2.hpp"

class Quadtree
{
   public:
    Quadtree(int level, const FloatRect2& bounds);

    void clear();
    void insert(Cell* cell);
    std::vector<Cell*> retrieve(const FloatRect2& area);

   private:
    int level;
    FloatRect2 bounds;
    std::vector<Cell*> cells;
    std::vector<Quadtree> nodes;

    void split();
    int getIndex(const FloatRect2& area);
};

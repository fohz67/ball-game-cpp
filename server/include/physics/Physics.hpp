#pragma once

#include "cell/Cell.hpp"
#include "geometry/Vector2.hpp"
#include <vector>

class Physics {
public:
    static void updateCellMovement(std::vector<Cell*>& cells, float normMouseX, float normMouseY);
    static void applyDecay(std::vector<Cell*>& cells);
    static void handleMerging(std::vector<Cell*>& cells);
    static void splitCell(std::vector<Cell*>& cells, uint32_t playerId, float normMouseX, float normMouseY);
    static void resolveRigidCollision(Cell* a, Cell* b);
    static bool resolveEat(Cell* predator, Cell* prey);
};


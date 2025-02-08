#pragma once

#include <limits>
#include <vector>

#include "config/Config.hpp"
#include "geometry/Vector2.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"

class AI
{
   public:
    static Vector2 computeAIMovement(const uint32_t myId);
};

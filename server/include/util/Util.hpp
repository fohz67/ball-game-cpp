#pragma once

#include <vector>

#include "geometry/Vector2.hpp"

class Util
{
   public:
    static Vector2 getRandomLocation();
    static std::vector<double> getRandomColor();
};

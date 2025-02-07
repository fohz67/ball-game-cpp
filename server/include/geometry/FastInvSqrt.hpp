#pragma once

#include <cmath>
#include <cstdint>

inline float FIS(float number)
{
    int32_t i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *reinterpret_cast<int32_t*>(&y);
    i = 0x5f3759df - (i >> 1);
    y = *reinterpret_cast<float*>(&i);
    y = y * (threehalfs - (x2 * y * y));

    return y;
}

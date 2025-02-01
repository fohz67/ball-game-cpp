#pragma once

#include <cstdint>
#include <vector>

struct CellData {
    uint32_t ownerId;
    uint32_t id;
    double x;
    double y;
    double radius;
    uint32_t color;
};

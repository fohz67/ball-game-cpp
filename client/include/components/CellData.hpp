#pragma once

#include <cstdint>

struct CellData {
    uint32_t id;
    uint32_t ownerId;
    double x;
    double y;
    double radius;
};

struct PelletData {
    uint32_t id;
    double x;
    double y;
    double radius;
    uint32_t color;
};

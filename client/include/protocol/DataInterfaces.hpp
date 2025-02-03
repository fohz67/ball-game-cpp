#pragma once

#include <cstdint>

struct WorldInterface {
    uint16_t size;
};

struct PlayerInterface {
    uint32_t id;
    uint32_t color;
    uint32_t cellColor;
};

struct CellInterface {
    uint32_t id;
    uint32_t ownerId;
    double x;
    double y;
    double radius;
};

struct PelletInterface {
    uint32_t id;
    double x;
    double y;
    double radius;
    uint32_t color;
};

struct ViewportInterface {
    double x;
    double y;
};

struct EntityInterface {
    uint8_t type;
    uint32_t id;
};

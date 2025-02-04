#pragma once

#include <cstdint>
#include <string>

struct WorldInterface {
    uint16_t size;
};

struct PlayerInterface {
    uint32_t id;
    std::string nickname;
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
    uint32_t id;
};

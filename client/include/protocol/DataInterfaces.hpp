#pragma once

#include <cstdint>
#include <string>

struct ICreateWorld
{
    uint16_t size;
};

struct ICreatePlayer
{
    uint32_t id;
    std::string nickname;
    uint32_t color;
    uint32_t cellColor;
};

struct IUpdateGameState
{
    uint32_t id;
    uint32_t ownerId;
    double x;
    double y;
    double radius;
};

struct ISpawnPellets
{
    uint32_t id;
    double x;
    double y;
    double radius;
    uint32_t color;
};

struct IUpdatePlayer
{
    double x;
    double y;
    uint32_t score;
    uint32_t totalMass;
    uint32_t cellCount;
};

struct IEntity
{
    uint32_t id;
};

struct IJoinServer
{
    std::string nickname;
};

struct IUpdateMousePosition
{
    double x;
    double y;
};

struct IUpdateLeaderboard
{
    std::string nickname;
};

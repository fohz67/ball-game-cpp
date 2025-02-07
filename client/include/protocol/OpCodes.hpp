#pragma once

#include <cstdint>

enum class OpCodes : uint8_t
{
    PINGPONG = 0,

    CREATE_WORLD = 1,

    JOIN_SERVER = 10,

    CREATE_PLAYER = 20,
    UPDATE_PLAYER = 21,
    DELETE_PLAYER = 22,

    SPAWN_PELLETS = 30,

    UPDATE_GAME_STATE = 40,
    UPDATE_LEADERBOARD = 41,

    DELETE_ENTITY = 50,

    UPDATE_MOUSE_POSITION = 60,
};

#pragma once

#include <cstdint>

enum class OpCodes : uint8_t {
    PINGPONG,
    WORLD_CREATED,
    JOIN_SERVER,
    NEW_PLAYER,
    UPDATE_CELL,
    CREATE_PELLETS,
    UPDATE_VIEWPORT,
    UPDATE_MOUSE_POSITION,
    KEY_PRESSED,
    DELETE_ENTITY,
    DELETE_PLAYER,
    UPDATE_SELF_DATA,
};

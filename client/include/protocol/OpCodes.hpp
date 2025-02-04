#pragma once

#include <cstdint>

enum class OpCodes : uint8_t {
    PINGPONG,
    WORLD,
    JOIN,
    PLAYER,
    CELL,
    PELLET,
    VIEWPORT,
    MOUSE_POSITION,
    KEY_PRESSED,
    ENTITY_REMOVED,
    PLAYER_DELETED,
};

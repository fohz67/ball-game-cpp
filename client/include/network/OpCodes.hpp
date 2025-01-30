#pragma once

#include <cstdint>

enum class OpCodes : uint8_t {
    WORLD = 1,
    JOIN = 2,
    GAME_STATE = 3,
    VIEWPORT = 4,
    MOUSE_POSITION = 5
};

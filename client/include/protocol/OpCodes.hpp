#pragma once

#include <cstdint>

enum class OpCodes : uint8_t {
    WORLD = 1,
    JOIN = 2,
    CELL = 3,
    VIEWPORT = 4,
    MOUSE_POSITION = 5,
    KEY_PRESSED = 6,
    ENTITY_REMOVED = 7
};

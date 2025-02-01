#pragma once

#include <cstdint>

struct Config {
    struct Server {
        static constexpr bool DEV_MODE = false;
    };

    struct Network {
        static constexpr int PORT = 12345;
        static constexpr int FREQUENCY = 5;
    };

    struct GameMode {
        static constexpr uint16_t WORLD_SIZE = 4000.0f;
        static constexpr double SPAWN_MASS = 200.0f;
        static constexpr double CELL_SPEED = 0.5;
        static constexpr double DECREASE_SPEED_THRESHOLD = 0.05;
    };
};

#pragma once

#include <cstdint>

struct Config {
    struct Server {
        static constexpr bool DEV_MODE = true;
    };

    struct Network {
        static constexpr int PORT = 12345;
        static constexpr int FREQUENCY = 3;
    };

    struct GameMode {
        // World
        static constexpr uint16_t WORLD_SIZE = 1000.0f;

        // Cell
        static constexpr double SPAWN_MASS = 4000.0f;
        static constexpr double CELL_SPEED = 0.3f;
        static constexpr double DECREASE_SPEED_THRESHOLD = 0.05;

        // Pellet
        static constexpr int PELLET_COUNT = 50;
        static constexpr double PELLET_MASS = 20.0f;
    };
};

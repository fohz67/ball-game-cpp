#pragma once

#include <cstdint>

struct Config {
    struct Server {
        static constexpr bool DEV_MODE = true;
    };

    struct Game {
        static constexpr int FREQUENCY = 3;
    };

    struct Network {
        static constexpr int PORT = 12345;
        static constexpr int FREQUENCY = 3;
    };

    struct GameMode {
        // World
        static constexpr uint16_t WORLD_SIZE = 700.0f;

        // Cell
        static constexpr double CELL_SPAWN_MASS = 2000.0f;
        static constexpr double CELL_SPEED = 0.07f;
        static constexpr double CELL_DECREASE_SPEED_THRESHOLD = 0.05f;
        static constexpr double CELL_DECAY_RATE = 0.02f;
        static constexpr double CELL_RADIUS_FACTOR = 1.0f;

        // Eat
        static constexpr double RESOLVE_EAT_FACTOR = 1.2f;
        static constexpr double RESOLVE_EAT_OVERLAP = 0.2f;

        // Pellet
        static constexpr int PELLET_COUNT = 200;
        static constexpr double PELLET_MASS = 2.0f;
        static constexpr double PELLET_EAT_FACTOR = 1.0f;
    };
};

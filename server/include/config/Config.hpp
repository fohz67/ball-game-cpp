#pragma once

#include <cstdint>

struct Config {
    struct Game {
        static constexpr int FREQUENCY = 1;
    };

    struct Network {
        static constexpr int PORT = 12345;
        static constexpr int FREQUENCY = 1;
        static constexpr int MAX_SIZE = 1024;
    };

    struct Gameplay {
        struct World {
            static constexpr uint16_t SIZE = 700.0f;
        };

        struct Cell {
            static constexpr double SPAWN_MASS = 2000.0f;
            static constexpr double SPEED = 0.07f;
            static constexpr double DECREASE_SPEED_THRESHOLD = 0.05f;
            static constexpr double DECAY_RATE = 0.02f;
            static constexpr int DECAY_TIMING = 1000;
        };

        struct Eat {
            static constexpr double RESOLVE_FACTOR = 1.2f;
            static constexpr double RESOLVE_OVERLAP = 0.2f;
        };

        struct Pellet {
            static constexpr int COUNT = 0;
            static constexpr double MASS = 2.0f;
            static constexpr double EAT_FACTOR = 2.0f;
        };
    };
};

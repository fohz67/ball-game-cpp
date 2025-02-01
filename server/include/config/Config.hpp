#pragma once

#include <cstdint>

struct Config {
    struct Server {
        static constexpr bool DEV_MODE = true;
    };

    struct Network {
        static constexpr int PORT = 12345;
        static constexpr int FREQUENCY = 50;
    };

    struct GameMode {
        static constexpr uint16_t WORLD_SIZE = 2000.0f;
        static constexpr double SPAWN_MASS = 200.0f;
    };
};

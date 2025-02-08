#pragma once

#include <cstdint>
#include <vector>

struct Config
{
    struct Game
    {
        static constexpr int FREQUENCY = 50;
        static constexpr bool DEBUG = false;
    };

    struct Network
    {
        static constexpr int PORT = 12345;
        static constexpr int FREQUENCY = 50;
        static constexpr int MAX_SIZE = 1024;
    };

    struct Quadtree
    {
        static constexpr int MAX_OBJECTS = 10;
        static constexpr int MAX_LEVELS = 5;
    };

    struct Gameplay
    {
        struct World
        {
            static constexpr uint16_t SIZE = 1500.0f;
        };

        struct Cell
        {
            static constexpr double SPAWN_MASS = 10000.0f;
            static constexpr double SPEED = 4.0f;
            static constexpr double DECREASE_SPEED_THRESHOLD = 0.05f;
            static constexpr double DECAY_RATE = 0.001f;
        };

        struct Bot
        {
            static constexpr int COUNT = 0;
            static constexpr double MASS = 1000.0f;
        };

        struct Eat
        {
            static constexpr double RESOLVE_FACTOR = 1.2f;
            static constexpr double RESOLVE_OVERLAP = 0.2f;
        };

        struct Pellet
        {
            static constexpr int COUNT = 2500;
            static constexpr double MASS = 4.0f;
            static constexpr double EAT_FACTOR = 4.0f;
        };

        struct Player
        {
            static inline std::vector<double> COLOR = {255, 255, 255, 255};
        };

        struct Leaderboard
        {
            static constexpr int COUNT = 10;
        };
    };
};

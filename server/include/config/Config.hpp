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
            static constexpr uint16_t SIZE = 1000.0f;
        };

        struct Cell
        {
            static constexpr double SPAWN_MASS = 5000.0f;
            static constexpr double SPEED = 3.0f;
            static constexpr double DECREASE_SPEED_THRESHOLD = 0.05f;
            static constexpr double DECAY_RATE = 0.0001;
            static constexpr double DECAY_EXPONENT = 1.2;
            static constexpr double DECAY_SCALING = 2.5;
            static constexpr double MIN_MASS = 10.0;
        };

        struct Bot
        {
            static constexpr int COUNT = 50;
            static constexpr double MASS = 5000.0f;
            static constexpr float ATTACK_INTENSITY = 1.5f;
            static constexpr float DEFENSE_INTENSITY = 2.0f;
            static constexpr float RANDOM_MOVEMENT_INTENSITY = 1.0f;
            static constexpr float HUNT_RADIUS = 1200.0f;
            static constexpr float ESCAPE_RADIUS = 500.0f;
            static constexpr float CHASE_ABORT_DISTANCE = 800.0f;
            static constexpr float MASS_ADVANTAGE_TO_ATTACK = 0.8f;
            static constexpr float MASS_DISADVANTAGE_TO_FLEE = 1.3f;
            static constexpr float RANDOM_WANDER_SPEED = 2.0f;
            static constexpr float WORLD_PADDING = 100.0f;
            static constexpr float MINIMUM_PELLET_HUNT = 400.0f;
            static constexpr float ABANDON_TARGET_TIME = 3000.0f;
        };

        struct Eat
        {
            static constexpr double RESOLVE_FACTOR = 1.2f;
            static constexpr double RESOLVE_OVERLAP = 0.2f;
        };

        struct Pellet
        {
            static constexpr int COUNT = 3000;
            static constexpr double MASS = 2.0f;
            static constexpr double EAT_FACTOR = 10.0f;
        };

        struct Player
        {
            static inline std::vector<double> COLOR = {255, 255, 255, 255};
            static constexpr int MAX_NICKNAME_LENGTH = 20;
            static inline std::string NICKNAME_TOO_LONG_FALLBACK = "Long Name";
            static inline std::string NICKNAME_EMPTY_FALLBACK = "An Unnamed Cell";
        };

        struct Leaderboard
        {
            static constexpr int MAX_ENTRIES = 10;
        };
    };
};

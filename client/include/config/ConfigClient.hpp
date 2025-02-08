#pragma once

#include <string>
#include <vector>

struct ConfigClient
{
    struct Game
    {
        static constexpr int FRAME_RATE = 144;
        static constexpr double CAMERA_INTERPOLATE_FACTOR = 0.1f;
    };

    struct Window
    {
        static constexpr int WIDTH = 1920;
        static constexpr int HEIGHT = 1080;
        static inline const char* NAME = "Ball game";
    };

    struct Network
    {
        static inline const char* HOST = "127.0.0.1";
        static constexpr int PORT = 12345;
        static constexpr int MAX_SIZE = 1024;
        static constexpr double ENTITY_LINKING_BIAS = 0.01;
    };

    struct World
    {
        static constexpr int ID = 1;
        static inline const std::vector<double> BACKGROUND_COLOR = {20, 20, 20, 255};
    };

    struct Zoom
    {
        static constexpr double SPEED = 50.0f;
    };

    struct Player
    {
        struct Nickname
        {
            static constexpr double TEXT_SIZE = 10.0f;
            static inline std::string FONT_FAMILY = "Montserrat";
            static constexpr int FONT_WEIGHT = 800;
        };

        struct Mass
        {
            static constexpr double TEXT_SIZE = 4.0f;
            static inline std::string FONT = "Montserrat";
            static constexpr int FONT_WEIGHT = 500;
        };
    };

    struct HUD
    {
        static inline const std::vector<double> BACKGROUND_COLOR = {255, 255, 255, 25};
        static constexpr double PADDING = 10.0f;
        static constexpr double TEXT_PADDING = 25.0f;
        static inline std::string FONT_FAMILY = "Montserrat";
        static inline const std::vector<double> TEXT_COLOR = {255, 255, 255, 255};

        struct Stats
        {
            static constexpr double WIDTH = 180.0f;
            static constexpr double HEIGHT = 220.0f;
            static constexpr double LABEL_SIZE = 18.0f;
            static constexpr double VALUE_SIZE = 19.0f;
            static constexpr int FONT_WEIGHT_LABEL = 500;
            static constexpr int FONT_WEIGHT_VALUE = 900;
            static inline const std::vector<double> VALUE_COLOR = {120, 107, 242, 255};
            static constexpr int MARGIN_TOP = 20;
            static constexpr int MARGIN_BETWEEN_LINES = 40;
        };

        struct Leaderboard
        {
            static constexpr double WIDTH = 250.0f;
            static constexpr double HEIGHT = 400.0f;
            static inline const std::string TITLE = "Leaderboard";
            static constexpr double TITLE_SIZE = 23.0f;
            static constexpr int FONT_WEIGHT_LABEL = 900;
            static constexpr int FONT_WEIGHT_VALUE = 700;
            static constexpr double CONTENT_SIZE = 18.0f;
            static constexpr int MARGIN_TOP = 40;
            static constexpr int MARGIN_BETWEEN_TITLE_AND_CONTENT = 85;
            static constexpr int MARGIN_BETWEEN_LINES = 50;
        };

        struct ChatBox
        {
            static constexpr double WIDTH = 350.0f;
            static constexpr double HEIGHT = 300.0f;
            static constexpr double TITLE_SIZE = 30.0f;
            static constexpr double CONTENT_SIZE = 30.0f;
        };
    };
};

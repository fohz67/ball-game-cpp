#pragma once

#include <string>
#include <vector>

struct ConfigClient {
    struct Game {
        static constexpr int    FRAME_RATE                = 120;
        static constexpr double CAMERA_INTERPOLATE_FACTOR = 0.1f;
    };

    struct Window {
        static constexpr int      WIDTH  = 1920;
        static constexpr int      HEIGHT = 1080;
        static inline const char* NAME   = "Ball game";
    };

    struct Network {
        static inline const char* HOST                = "127.0.0.1";
        static constexpr int      PORT                = 12345;
        static constexpr int      MAX_SIZE            = 1024;
        static constexpr double   ENTITY_LINKING_BIAS = 0.01;
    };

    struct World {
        static constexpr int                    ID               = 1;
        static inline const std::vector<double> BACKGROUND_COLOR = {20, 20, 20, 255};
    };

    struct Zoom {
        static constexpr double ZOOM_SPEED = 50.0f;
    };

    struct Player {
        struct Nickname {
            static constexpr double   NICKNAME_TEXT_SIZE   = 10.0f;
            static inline std::string NICKNAME_FONT_FAMILY = "Montserrat";
            static constexpr int      NICKNAME_FONT_WEIGHT = 800;
        };

        struct Mass {
            static constexpr double   MASS_TEXT_SIZE   = 4.0f;
            static inline std::string MASS_FONT        = "Montserrat";
            static constexpr int      MASS_FONT_WEIGHT = 500;
        };
    };

    struct HUD {
        struct Stats {
            static constexpr double                 WIDTH            = 150.0f;
            static constexpr double                 HEIGHT           = 90.0f;
            static constexpr double                 PADDING          = 10.0f;
            static inline const std::vector<double> BACKGROUND_COLOR = {255, 255, 255, 25};
        };

        struct Leaderboard {
            static constexpr double                 WIDTH            = 250.0f;
            static constexpr double                 HEIGHT           = 400.0f;
            static constexpr double                 PADDING          = 10.0f;
            static inline const std::vector<double> BACKGROUND_COLOR = {255, 255, 255, 25};
        };

        struct ChatBox {
            static constexpr double                 WIDTH            = 350.0f;
            static constexpr double                 HEIGHT           = 300.0f;
            static constexpr double                 PADDING          = 10.0f;
            static inline const std::vector<double> BACKGROUND_COLOR = {255, 255, 255, 25};
        };
    };
};

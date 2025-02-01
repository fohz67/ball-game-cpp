#pragma once

#include <vector>

struct ConfigClient {
    struct Client {
        static constexpr bool DEV_MODE = false;
    };

    struct Game {
        static constexpr int FRAME_RATE = 144;
        static constexpr double CAMERA_INTERPOLATE_FACTOR = 0.1f;
    };

    struct Window {
        static constexpr int WIDTH = 1920;
        static constexpr int HEIGHT = 1080;
        static inline const char* NAME = "Ball game";
    };

    struct Network {
        static constexpr int FREQUENCY = 50;
        static inline const char* HOST = "127.0.0.1";
        static constexpr int PORT = 12345;
    };

    struct World {
        static constexpr int ID = 0;
        static inline const std::vector<double> BACKGROUND_COLOR = {20, 20, 20,
                                                                    255};
        static constexpr int BORDER_WIDTH = 50;
        static inline const std::vector<double> BORDER_COLOR = {255, 255, 255,
                                                                255};
    };
};

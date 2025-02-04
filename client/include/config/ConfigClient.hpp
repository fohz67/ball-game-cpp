#pragma once

#include <vector>

struct ConfigClient {
    struct Game {
        static constexpr int FRAME_RATE = 120;
        static constexpr double CAMERA_INTERPOLATE_FACTOR = 0.1f;
    };

    struct Window {
        static constexpr int WIDTH = 1920;
        static constexpr int HEIGHT = 1080;
        static inline const char* NAME = "Ball game";
    };

    struct Network {
        static inline const char* HOST = "127.0.0.1";
        static constexpr int PORT = 12345;
        static constexpr int MAX_SIZE = 1024;
        static constexpr int ENTITY_LINKING_BIAS = 10000;
    };

    struct World {
        static constexpr int ID = 1;
        static inline const std::vector<double> BACKGROUND_COLOR = {20, 20, 20,
                                                                    255};
    };

    struct Zoom {
        static constexpr double ZOOM_SPEED = 50.0f;
    };
};

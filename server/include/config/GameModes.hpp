#pragma once

namespace GameMode {

namespace FFA {
    constexpr float WORLD_EAT_OVERLAP_REQ = 0.35f;
    constexpr float WORLD_EAT_SIZE_REQ = 1.2f;
    constexpr float WORLD_FRICTION = 0.95f;
    constexpr float WORLD_SIZE = 5000.0f;
    constexpr int MAX_CELLS = 16;
    constexpr float MERGE_TIME = 5.0f;
    constexpr float MERGE_TIME_SCALE = 0.25f;
    constexpr float MIN_MASS_TO_EJECT = 40.0f;
    constexpr float MIN_MASS_TO_SPLIT = 126.0f;
    constexpr float SPAWN_MASS = 200.0f;
    constexpr float BASE_SPEED = 0.007f;
    constexpr float SPEED_EXPONENT = -0.4396754f;
    constexpr float DECAY_RATE = 0.0005f;
    constexpr float DECAY_SCALE = 0.999f;
}

namespace Mega {
    constexpr float WORLD_EAT_OVERLAP_REQ = 0.35f;
    constexpr float WORLD_EAT_SIZE_REQ = 1.2f;
    constexpr float WORLD_FRICTION = 0.9f;
    constexpr float WORLD_SIZE = 7000.0f;
    constexpr int MAX_CELLS = 400;
    constexpr float MERGE_TIME = 2.0f;
    constexpr float MERGE_TIME_SCALE = 0.25f;
    constexpr float MIN_MASS_TO_EJECT = 40.0f;
    constexpr float MIN_MASS_TO_SPLIT = 126.0f;
    constexpr float SPAWN_MASS = 20000.0f;
    constexpr float BASE_SPEED = 0.015f;
    constexpr float SPEED_EXPONENT = -0.3f;
    constexpr float DECAY_RATE = 2000.0f;
    constexpr float DECAY_SCALE = 0.999f;
}

#define CURRENT_GAMEMODE GameMode::FFA

}

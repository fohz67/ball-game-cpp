#pragma once

namespace Config {
namespace Network {
constexpr const int PORT = 12345;
constexpr int FREQUENCY = 50;
} // namespace Network

namespace World {
constexpr const int WIDTH = 300;
constexpr const int HEIGHT = 300;
} // namespace World

namespace Cell {
constexpr const float DEFAULT_RADIUS = 200;
constexpr const float DEFAULT_SPEED = 100;
} // namespace Cell

namespace GameMode {
constexpr float WORLD_EAT_OVERLAP_REQ = 0.35f;
constexpr float WORLD_EAT_SIZE_REQ = 1.2f;
constexpr float WORLD_FRICTION = 0.95f;
constexpr float WORLD_SIZE = 700.0f;

constexpr int MAX_CELLS = 400;
constexpr float MERGE_TIME = 2000.0f;
constexpr float MERGE_TIME_SCALE = 0.25f;
constexpr float MIN_MASS_TO_EJECT = 40.0f;
constexpr float MIN_MASS_TO_SPLIT = 126.0f;
constexpr float SPAWN_MASS = 20000.0f;
constexpr float BASE_SPEED = 10.0f;
constexpr float SPEED_EXPONENT = -0.4396754f;

constexpr float SPLIT_BOOST = 2.0f;
constexpr int SPLIT_RESOLVE_DELAY = 450;
constexpr int SPLIT_DELAY_TICKS = 3;

constexpr float EJECT_BOOST = 2.0f;
constexpr int EJECT_DELAY_TICKS = 3;
constexpr float EJECT_DISPERSION = 0.1f;
constexpr int EJECT_LIFETIME = 10000;
constexpr float EJECT_MASS = 16.0f;
constexpr float EJECT_PUSH_MULTIPLIER = 0.0025f;

constexpr float POP_BOOST = 2.0f;
constexpr int VIRUS_COUNT = 0;
constexpr float VIRUS_PUSH_BOOST = 1.0f;
constexpr float VIRUS_MASS = 150.0f;

constexpr int PELLET_COUNT = 1000;
constexpr float PELLET_MASS = 2.0f;

constexpr int DEAD_CELL_LIFETIME = 10000;

constexpr int DECAY_RATE = 2000;
constexpr float DECAY_SCALE = 0.999f;
} // namespace GameMode
} // namespace Config

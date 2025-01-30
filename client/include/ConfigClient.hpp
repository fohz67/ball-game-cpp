#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace ConfigClient {
namespace Network {
constexpr const char* HOST = "127.0.0.1";
constexpr int PORT = 12345;
} // namespace Network

namespace Window {
constexpr int WIDTH = 1920;
constexpr int HEIGHT = 1080;
constexpr const char* NAME = "Ball Game";
static std::vector<double> BACKGROUND_COLOR = {0, 0, 0, 255};
} // namespace Window

namespace World {
constexpr int ID = 0;
static std::vector<double> BACKGROUND_COLOR = {20, 20, 20, 255};
constexpr int BORDER_WIDTH = 50;
static std::vector<double> BORDER_COLOR = {255, 255, 255, 255};
} // namespace World

namespace Cell {
constexpr float DEFAULT_RADIUS = 20;
constexpr float DEFAULT_SPEED = 100;
static std::vector<double> DEFAULT_COLOR = {0, 255, 0, 255};
constexpr float SAFER = 10000;
} // namespace Cell
} // namespace ConfigClient

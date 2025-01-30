#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace GameConfig {
constexpr const char* HOST = "127.0.0.1";
constexpr int PORT = 12345;

constexpr int WINDOW_WIDTH = 1920;
constexpr int WINDOW_HEIGHT = 1080;
constexpr const char* WINDOW_NAME = "Ball Game";

constexpr int BORDER_SIZE = 50;
static const sf::Color BACKGROUND_COLOR = sf::Color::Black;
static const sf::Color WORLD_COLOR = sf::Color(20, 20, 20);
static const sf::Color BORDER_COLOR = sf::Color::White;
} // namespace GameConfig

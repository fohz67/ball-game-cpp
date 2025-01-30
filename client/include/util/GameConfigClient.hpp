#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace GameConfigClient {
// Network
constexpr const char* HOST = "127.0.0.1";
constexpr int PORT = 12345;

// Window
constexpr int WINDOW_WIDTH = 1920;
constexpr int WINDOW_HEIGHT = 1080;
constexpr const char* WINDOW_NAME = "Ball Game";
static const sf::Color WINDOW_BACKGROUND_COLOR = sf::Color::Black;

// World
constexpr int WORLD_BORDER_WIDTH = 50;
static const sf::Color WORLD_BACKGROUND_COLOR = sf::Color(20, 20, 20);
static const sf::Color WOLRD_BORDER_COLOR = sf::Color::White;
} // namespace GameConfigClient

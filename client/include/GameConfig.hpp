#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace GameConfig {
constexpr const char* HOST = "127.0.0.1";
constexpr int PORT = 12345;

constexpr int BORDER_SIZE = 10;
static const sf::Color BACKGROUND_COLOR = sf::Color::Black;
static const sf::Color WORLD_COLOR = sf::Color(50, 50, 50);
static const sf::Color BORDER_COLOR = sf::Color(0, 0, 255);
} // namespace GameConfig

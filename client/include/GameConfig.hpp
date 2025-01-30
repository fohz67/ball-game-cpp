#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace GameConfig {
constexpr const char* HOST = "127.0.0.1";
constexpr int PORT = 12345;

constexpr int BORDER_SIZE = 50;
static const sf::Color BACKGROUND_COLOR = sf::Color::Black;
static const sf::Color WORLD_COLOR = sf::Color(20, 20, 20);
static const sf::Color BORDER_COLOR = sf::Color::White;
} // namespace GameConfig

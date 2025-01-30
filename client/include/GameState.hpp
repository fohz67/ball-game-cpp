#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GameState
{
public:
    GameState();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    sf::Color backgroundColor;
};

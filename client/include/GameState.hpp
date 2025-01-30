#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GameState {
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

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GameState {
  public:
    GameState(const GameState&) = delete;
    GameState& operator=(const GameState&) = delete;
    static GameState& get();
    void run();

  private:
    GameState() = default;
    ~GameState() = default;
    void processEvents();
    void update();
    void render();
    sf::RenderWindow window;
    sf::Color backgroundColor;
};

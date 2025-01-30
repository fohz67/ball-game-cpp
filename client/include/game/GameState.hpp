#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "System.hpp"

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
    void render(GameEngine::System& system);
    sf::RenderWindow window;
    sf::Color backgroundColor;
};

#pragma once

#include <SFML/Graphics.hpp>
#include "System.hpp"

class GameClient {
  public:
    GameClient(const GameClient&) = delete;
    GameClient& operator=(const GameClient&) = delete;

    static GameClient& get();

    void run();

  private:
    GameClient() = default;
    ~GameClient() = default;

    void initWindow();
    void initView();
    void processEvents();
    void render(GEngine::System& system);

    sf::RenderWindow window;
    sf::View view;
};

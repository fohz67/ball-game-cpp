#pragma once

#include <SFML/Graphics.hpp>
#include "System.hpp"
#include "components/Viewport.hpp"

class GameClient {
  public:
    GameClient(const GameClient&) = delete;
    GameClient& operator=(const GameClient&) = delete;

    static GameClient& get();

    void run();
    Viewport getViewport() const;

  private:
    GameClient() = default;
    ~GameClient() = default;

    void processEvents();
    void render(GameEngine::System& system);

    sf::RenderWindow window;
    sf::View view;
    Viewport viewport;
};

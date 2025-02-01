#pragma once

#include <SFML/Graphics.hpp>
#include "System.hpp"

class GameClient {
  public:
    GameClient(const GameClient&) = delete;
    GameClient& operator=(const GameClient&) = delete;

    static GameClient& get();

    void run();

    std::pair<double, double> getViewport() const;
    void setViewport(std::pair<double, double> viewport);

  private:
    GameClient() = default;
    ~GameClient() = default;

    void initWindow();
    void initView();
    void processEvents();
    void render(GameEngine::System& system, double alpha);

    sf::RenderWindow window;
    sf::View view;
    std::pair<double, double> prevViewport = {0, 0};
    std::pair<double, double> viewport;
};

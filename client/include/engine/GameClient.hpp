#pragma once

#include <SFML/Graphics.hpp>

#include "System.hpp"

class GameClient
{
   public:
    GameClient(const GameClient&) = delete;
    GameClient& operator=(const GameClient&) = delete;

    static GameClient& get();

    const void run();

    sf::RenderWindow& getWindow();
    sf::View& getView();
    sf::Vector2u getWindowSize() const;
    int getFPS() const;

   private:
    GameClient() = default;
    ~GameClient() = default;

    const void initWindow();
    const void initView();
    const void processEvents();
    const void render(GameEngine::System& system, float deltaTime);

    sf::RenderWindow window;
    sf::View view;
    sf::Vector2u windowSize;

    int fps = 0;
};

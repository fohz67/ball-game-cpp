#include "GameState.hpp"

GameState::GameState()
    : window(sf::VideoMode({1920, 1080}), "Ball Game"), backgroundColor(sf::Color(30, 30, 30)) {}

void GameState::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void GameState::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return;
        }
    }
}

void GameState::update()
{
}

void GameState::render()
{
    window.clear(backgroundColor);
    window.display();
}

#include "game_components/GameState.hpp"
#include "GameConfig.hpp"
#include "game_components/CWorld.hpp"

GameState& GameState::get() {
    static GameState instance;
    return instance;
}

void GameState::run() {
    window.create(sf::VideoMode(1920, 1080), "Ball Game");

    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void GameState::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return;
        }
        if (event.type == sf::Event::MouseWheelScrolled) {
            if (event.mouseWheelScroll.delta > 0)
                CWorld::get().zoom(1.1f);
            else if (event.mouseWheelScroll.delta < 0)
                CWorld::get().zoom(0.9f);
        }
    }
}

void GameState::update() {}

void GameState::render() {
    window.clear(GameConfig::BACKGROUND_COLOR);
    CWorld::get().render(window);
    window.display();
}

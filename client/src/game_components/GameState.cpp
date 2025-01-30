#include "game_components/GameState.hpp"
#include "GameConfig.hpp"

GameState& GameState::get() {
    static GameState instance;
    return instance;
}

void GameState::run() {
    window = sf::VideoMode({1920, 1080}), "Ball Game";

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
    }
}

void GameState::update() {}

void GameState::render() {
    window.clear(GameConfig::BACKGROUND_COLOR);
    window.display();
}

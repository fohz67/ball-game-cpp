#include "util/GameState.hpp"
#include "comps/world/WorldClient.hpp"
#include "util/GameConfigClient.hpp"

GameState& GameState::get() {
    static GameState instance;
    return instance;
}

void GameState::run() {
    window.create(
        sf::VideoMode(GameConfigClient::WINDOW_WIDTH, GameConfigClient::WINDOW_HEIGHT),
        GameConfigClient::WINDOW_NAME);

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
            if (event.mouseWheelScroll.delta > 0) {
                WorldClient::get().zoom(1.1f);
            } else if (event.mouseWheelScroll.delta < 0) {
                WorldClient::get().zoom(0.9f);
            }
        }
    }
}

void GameState::update() {}

void GameState::render() {
    window.clear(GameConfigClient::WINDOW_BACKGROUND_COLOR);
    WorldClient::get().render(window);
    window.display();
}

#include "game/GameState.hpp"
#include "ConfigClient.hpp"
#include "entity/EntityManager.hpp"

GameState& GameState::get() {
    static GameState instance;
    return instance;
}

void GameState::run() {
    window.create(sf::VideoMode(ConfigClient::Window::WIDTH,
                                ConfigClient::Window::HEIGHT),
                  ConfigClient::Window::NAME);
    GameEngine::System system;
    while (window.isOpen()) {
        processEvents();
        render(system);
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
                //
            } else if (event.mouseWheelScroll.delta < 0) {
                //
            }
        }
    }
}

void GameState::render(GameEngine::System& system) {
    window.clear();
    std::map<int, GameEngine::Entity> entitiesList =
        EntityManager::get().getEntities();
    if (!entitiesList.empty()) {
        system.render(window, entitiesList);
    }
    window.display();
}

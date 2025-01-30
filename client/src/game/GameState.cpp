#include "game/GameState.hpp"
#include "comps/world/WorldClient.hpp"
#include "entity/EntityManager.hpp"
#include "game/GameConfigClient.hpp"

GameState& GameState::get() {
    static GameState instance;
    return instance;
}

void GameState::run() {
    window.create(sf::VideoMode(GameConfigClient::WINDOW_WIDTH,
                                GameConfigClient::WINDOW_HEIGHT),
                  GameConfigClient::WINDOW_NAME);
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
                WorldClient::get().zoom(1.1f);
            } else if (event.mouseWheelScroll.delta < 0) {
                WorldClient::get().zoom(0.9f);
            }
        }
    }
}

void GameState::render(GameEngine::System& system) {
    window.clear();
    std::map<int, GameEngine::Entity> entitiesList =
        EntityManager::get().getEntities();
    if (!entitiesList.empty()) {
        std::cout << "Entities: " << entitiesList.size() << std::endl;
        system.render(window, entitiesList);
    }
    window.display();
}

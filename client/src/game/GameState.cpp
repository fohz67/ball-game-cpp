#include "game/GameState.hpp"
#include "ConfigClient.hpp"
#include "network/ProtocolClient.hpp"
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
    sf::Clock clock;
    sf::Vector2i lastMousePos = sf::Mouse::getPosition(window);
    while (window.isOpen()) {
        processEvents();
        if (clock.getElapsedTime().asMilliseconds() >= ConfigClient::Network::FREQUENCY) {
            ProtocolClient::sendMousePosition(window, lastMousePos);
            clock.restart();
        }
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

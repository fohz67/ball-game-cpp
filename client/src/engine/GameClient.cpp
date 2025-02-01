#include "engine/GameClient.hpp"
#include "components/Hotkeys.hpp"
#include "config/ConfigClient.hpp"
#include "managers/EntityManager.hpp"
#include "protocol/ProtocolClient.hpp"

GameClient& GameClient::get() {
    static GameClient instance;
    return instance;
}

void GameClient::run() {
    window.create(sf::VideoMode(ConfigClient::Window::WIDTH,
                                ConfigClient::Window::HEIGHT),
                  ConfigClient::Window::NAME);

    GameEngine::System system;
    sf::Clock clock;
    sf::Vector2i lastMousePos = sf::Mouse::getPosition(window);

    view.setSize(ConfigClient::Window::WIDTH, ConfigClient::Window::HEIGHT);
    view.setCenter(viewport.x, viewport.y);

    while (window.isOpen()) {
        processEvents();

        if (clock.getElapsedTime().asMilliseconds() >=
            ConfigClient::Loop::FREQUENCY) {
            ProtocolClient::sendMousePosition(window, lastMousePos);

            clock.restart();
        }

        render(system);
    }
}

Viewport GameClient::getViewport() const {
    return viewport;
}

void GameClient::processEvents() {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return;
        }
        if (event.type == sf::Event::KeyPressed) {
            ProtocolClient::sendKeyPressed(
                Hotkeys::keyToString(event.key.code));
        }
    }
}

void GameClient::render(GameEngine::System& system) {
    std::map<int, GameEngine::Entity> entitiesList =
        EntityManager::get().getEntities();

    view.setCenter(viewport.x, viewport.y);

    window.setView(view);
    window.clear();

    if (!entitiesList.empty()) {
        system.render(window, entitiesList);
    }

    window.display();
}

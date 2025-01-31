#include "game/GameState.hpp"
#include "ConfigClient.hpp"
#include "entity/EntityManager.hpp"
#include "game/Hotkeys.hpp"
#include "network/ProtocolClient.hpp"

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
    view.setSize(ConfigClient::Window::WIDTH, ConfigClient::Window::HEIGHT);
    view.setCenter(viewportX, viewportY);
    originalViewSize = view.getSize();
    while (window.isOpen()) {
        processEvents();
        if (clock.getElapsedTime().asMilliseconds() >=
            ConfigClient::Network::FREQUENCY) {
            ProtocolClient::sendMousePosition(window, lastMousePos);
            clock.restart();
        }
        render(system);
    }
}

void GameState::setViewport(float x, float y) {
    viewportX = x;
    viewportY = y;
}

void GameState::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return;
        }
        if (event.type == sf::Event::KeyPressed) {
            std::string keyName = Hotkeys::keyToString(event.key.code);
            ProtocolClient::sendKeyPressed(keyName);
        }
        if (event.type == sf::Event::MouseWheelScrolled) {
            float zoomFactor = (event.mouseWheelScroll.delta > 0) ? 0.9f : 1.1f;
            float newZoom = currentZoom * zoomFactor;
            if (newZoom >= 0.5f && newZoom <= 2.0f) {
                currentZoom = newZoom;
                view.setSize(originalViewSize * currentZoom);
            }
        }
    }
}

void GameState::render(GameEngine::System& system) {
    view.setCenter(viewportX, viewportY);
    window.setView(view);
    window.clear();
    std::map<int, GameEngine::Entity> entitiesList =
        EntityManager::get().getEntities();
    if (!entitiesList.empty()) {
        system.render(window, entitiesList);
    }
    window.display();
}

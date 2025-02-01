#include "engine/GameClient.hpp"
#include <components/Position.hpp>
#include "components/Hotkeys.hpp"
#include "components/Viewport.hpp"
#include "config/ConfigClient.hpp"
#include "managers/EntityManager.hpp"
#include "protocol/ProtocolClient.hpp"

GameClient& GameClient::get() {
    static GameClient instance;
    return instance;
}

void GameClient::run() {
    GameEngine::System system;
    sf::Vector2i lastMousePos = sf::Mouse::getPosition(window);

    initWindow();
    initView();

    while (window.isOpen()) {
        processEvents();
        ProtocolClient::get().sendMousePosition(window, lastMousePos);
        Viewport::get().applyInterpolation();
        render(system);
    }
}

void GameClient::initWindow() {
    window.create(sf::VideoMode(ConfigClient::Window::WIDTH,
                                ConfigClient::Window::HEIGHT),
                  ConfigClient::Window::NAME);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(ConfigClient::Game::FRAME_RATE);
}

void GameClient::initView() {
    view.setSize(ConfigClient::Window::WIDTH, ConfigClient::Window::HEIGHT);
    view.setCenter(ConfigClient::Window::WIDTH / 2,
                   ConfigClient::Window::HEIGHT / 2);
    window.setView(view);
}

void GameClient::processEvents() {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return;
        }
        if (event.type == sf::Event::KeyPressed) {
            ProtocolClient::get().sendKeyPressed(
                Hotkeys::keyToString(event.key.code));
        }
    }
}

void GameClient::render(GameEngine::System& system) {
    view.setCenter(Viewport::get().getPreviousViewport().first,
                   Viewport::get().getPreviousViewport().second);

    window.setView(view);
    window.clear();

    system.render(window, EntityManager::get().entities);

    window.display();
}

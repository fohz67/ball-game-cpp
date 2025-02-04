#include "engine/GameClient.hpp"
#include <components/Position.hpp>
#include "components/HUD.hpp"
#include "components/Hotkeys.hpp"
#include "components/Viewport.hpp"
#include "components/Zoom.hpp"
#include "config/ConfigClient.hpp"
#include "managers/EntityManager.hpp"
#include "protocol/ProtocolClient.hpp"

GameClient& GameClient::get() {
    static GameClient instance;
    return instance;
}

void GameClient::run() {
    GEngine::System system;
    sf::Vector2i    lastMousePos = sf::Mouse::getPosition(window);
    sf::Clock       clock;
    float           deltaTime = 0.0f;

    initWindow();
    initView();

    HUD::get().create();

    while (window.isOpen()) {
        processEvents();

        ProtocolClient::get().sendMousePosition(window, lastMousePos);
        Viewport::get().applyInterpolation();

        deltaTime = clock.restart().asSeconds();
        fps       = static_cast<int>(1.0f / deltaTime);
        HUD::get().update();

        render(system);
    }
}

void GameClient::initWindow() {
    window.create(sf::VideoMode(ConfigClient::Window::WIDTH, ConfigClient::Window::HEIGHT),
                  ConfigClient::Window::NAME);
    windowSize = sf::Vector2u(window.getView().getSize());
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(ConfigClient::Game::FRAME_RATE);
}

void GameClient::initView() {
    view.setSize(ConfigClient::Window::WIDTH, ConfigClient::Window::HEIGHT);
    view.setCenter(ConfigClient::Window::WIDTH / 2, ConfigClient::Window::HEIGHT / 2);
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
            ProtocolClient::get().sendKeyPressed(Hotkeys::keyToString(event.key.code));
        }
        if (event.type == sf::Event::MouseWheelScrolled) {
            if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                Zoom::get().setZoom(event.mouseWheelScroll.delta, view);
            }
        }
    }
}

void GameClient::render(GEngine::System& system) {
    // Gameplay
    view.setCenter(
        Viewport::get().getPreviousViewport().first, Viewport::get().getPreviousViewport().second);
    window.setView(view);
    window.clear();

    std::map<double, GEngine::Entity> gameEntities = EntityManager::get().getGameEntities();
    system.render(window, gameEntities);

    // HUD
    window.setView(window.getDefaultView());
    std::map<double, GEngine::Entity> hudEntities = EntityManager::get().getHUDEntities();
    system.render(window, hudEntities);

    // Final render
    window.display();
}

sf::RenderWindow& GameClient::getWindow() {
    return window;
}

sf::View& GameClient::getView() {
    return view;
}

sf::Vector2u GameClient::getWindowSize() const {
    return windowSize;
}

int GameClient::getFPS() const {
    return fps;
}

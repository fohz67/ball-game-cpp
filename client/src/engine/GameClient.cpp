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
    GameEngine::System system;
    sf::Clock clock;
    sf::Clock renderClock;
    sf::Vector2i lastMousePos = sf::Mouse::getPosition(window);

    double lastUpdateTime = clock.getElapsedTime().asSeconds();

    initWindow();
    initView();

    while (window.isOpen()) {
        double currentTime = clock.getElapsedTime().asSeconds();
        double deltaTime = currentTime - lastUpdateTime;
        lastUpdateTime = currentTime;

        processEvents();
        ProtocolClient::sendMousePosition(window, lastMousePos);

        double alpha = deltaTime / ConfigClient::Game::TICK_RATE;
        alpha = std::min(1.0, std::max(0.0, alpha));

        render(system, alpha);
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
            ProtocolClient::sendKeyPressed(
                Hotkeys::keyToString(event.key.code));
        }
    }
}

void GameClient::render(GameEngine::System& system, double alpha) {
    prevViewport.first += (viewport.first - prevViewport.first) * ConfigClient::Game::CAMERA_PANNING_DELAY;
    prevViewport.second += (viewport.second - prevViewport.second) * ConfigClient::Game::CAMERA_PANNING_DELAY;

    view.setCenter(prevViewport.first, prevViewport.second);
    window.setView(view);
    window.clear();
    system.render(window, EntityManager::get().getEntities());
    window.display();
}

std::pair<double, double> GameClient::getViewport() const {
    return viewport;
}

void GameClient::setViewport(std::pair<double, double> viewport) {
    this->viewport = viewport;
}

#include "engine/GameClient.hpp"

#include <components/Position.hpp>

#include "components/HUD.hpp"
#include "components/Hotkeys.hpp"
#include "components/Viewport.hpp"
#include "components/Zoom.hpp"
#include "config/ConfigClient.hpp"
#include "managers/EntityManager.hpp"
#include "protocol/SendClient.hpp"

GameClient& GameClient::get()
{
    static GameClient instance;
    return instance;
}

const void GameClient::run()
{
    GameEngine::System system;

    sf::Vector2i lastMousePos = sf::Mouse::getPosition(window);
    sf::Clock clock;
    float deltaTime = 0.0f;

    initWindow();
    initView();

    HUD::get().create();

    while (window.isOpen())
    {
        processEvents();

        deltaTime = clock.restart().asSeconds();
        fps = static_cast<int>(1.0f / deltaTime);

        SendClient::sendMousePosition(window, lastMousePos);
        Viewport::get().applyInterpolation();
        HUD::get().update();

        render(system);
    }
}

const void GameClient::initWindow()
{
    window.create(sf::VideoMode(ConfigClient::Window::WIDTH, ConfigClient::Window::HEIGHT),
                  ConfigClient::Window::NAME);

    windowSize = sf::Vector2u(window.getView().getSize());

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(ConfigClient::Game::FRAME_RATE);
}

const void GameClient::initView()
{
    view.setSize(ConfigClient::Window::WIDTH, ConfigClient::Window::HEIGHT);
    view.setCenter(ConfigClient::Window::WIDTH / 2, ConfigClient::Window::HEIGHT / 2);

    window.setView(view);
}

const void GameClient::processEvents()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return;
        }

        if (event.type == sf::Event::KeyPressed)
        {
            // @TODO refactor this
        }

        if (event.type == sf::Event::MouseWheelScrolled)
        {
            if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
            {
                Zoom::get().setZoom(event.mouseWheelScroll.delta, view);
            }
        }
    }
}

const void GameClient::render(GameEngine::System& system)
{
    view.setCenter(Viewport::get().getPreviousViewport().first,
                   Viewport::get().getPreviousViewport().second);

    window.setView(view);
    window.clear();

    std::map<double, GameEngine::Entity> gameEntities = EntityManager::get().getGameEntities();
    system.render(window, gameEntities);

    window.setView(window.getDefaultView());
    std::map<double, GameEngine::Entity> hudEntities = EntityManager::get().getHUDEntities();
    system.render(window, hudEntities);

    window.display();
}

sf::RenderWindow& GameClient::getWindow() { return window; }

sf::View& GameClient::getView() { return view; }

sf::Vector2u GameClient::getWindowSize() const { return windowSize; }

int GameClient::getFPS() const { return fps; }

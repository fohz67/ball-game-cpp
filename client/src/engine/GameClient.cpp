#include "engine/GameClient.hpp"

#include <components/Position.hpp>

#include "components/HUD.hpp"
#include "components/Hotkeys.hpp"
#include "components/Viewport.hpp"
#include "components/Zoom.hpp"
#include "config/ConfigClient.hpp"
#include "engine/NetworkClient.hpp"
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

        SendClient::sendMousePosition(window, lastMousePos);
        Viewport::get().applyInterpolation();
        HUD::get().update();

        deltaTime = clock.restart().asSeconds();
        fps = static_cast<int>(1.0f / deltaTime);

        render(system, deltaTime);
    }
}

const void GameClient::initWindow()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    window.create(sf::VideoMode(ConfigClient::Window::WIDTH, ConfigClient::Window::HEIGHT),
                  ConfigClient::Window::NAME,
                  sf::Style::Default,
                  settings);

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
            NetworkClient::get().stop();
            window.close();
            return;
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

const void GameClient::render(GameEngine::System& system, float deltaTime)
{
    view.setCenter(Viewport::get().getPreviousViewport().first,
                   Viewport::get().getPreviousViewport().second);

    window.setView(view);
    window.clear();

    system.render(window, EntityManager::get().entities, deltaTime);

    window.setView(window.getDefaultView());
    system.render(window, EntityManager::get().hudEntities, deltaTime);

    window.display();
}

sf::RenderWindow& GameClient::getWindow()
{
    return window;
}

sf::View& GameClient::getView()
{
    return view;
}

sf::Vector2u GameClient::getWindowSize() const
{
    return windowSize;
}

int GameClient::getFPS() const
{
    return fps;
}

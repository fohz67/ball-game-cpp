#include "comps/world/WorldClient.hpp"
#include <iostream>
#include "util/GameConfigClient.hpp"

WorldClient& WorldClient::get() {
    static WorldClient instance;
    return instance;
}

void WorldClient::init(int worldWidth, int worldHeight) {
    width = worldWidth;
    height = worldHeight;
    scaleFactor = 1.0f;
    create(worldWidth, worldHeight);
}

void WorldClient::create(int worldWidth, int worldHeight) {
    worldRect.setFillColor(GameConfigClient::WORLD_BACKGROUND_COLOR);
    worldRect.setOutlineThickness(GameConfigClient::WORLD_BORDER_WIDTH);
    worldRect.setOutlineColor(GameConfigClient::WOLRD_BORDER_COLOR);
    worldRect.setSize(
        sf::Vector2f(static_cast<float>(width), static_cast<float>(height)));
    worldRect.setOrigin(width / 2.0f, height / 2.0f);
    worldRect.setPosition(GameConfigClient::WINDOW_WIDTH / 2.0f,
                          GameConfigClient::WINDOW_HEIGHT / 2.0f);
}

void WorldClient::zoom(float factor) {
    scaleFactor *= factor;
    worldRect.setScale(scaleFactor, scaleFactor);
}

void WorldClient::render(sf::RenderWindow& window) {
    window.draw(worldRect);
}

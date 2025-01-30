#include "game_components/CWorld.hpp"
#include <iostream>
#include "GameConfig.hpp"

CWorld& CWorld::get() {
    static CWorld instance;
    return instance;
}

void CWorld::init(int worldWidth, int worldHeight) {
    width = worldWidth;
    height = worldHeight;
    worldRect.setFillColor(GameConfig::WORLD_COLOR);
    worldRect.setOutlineThickness(GameConfig::BORDER_SIZE);
    worldRect.setOutlineColor(GameConfig::BORDER_COLOR);
    worldRect.setSize(
        sf::Vector2f(static_cast<float>(width), static_cast<float>(height)));
    worldRect.setPosition((1920 - width) / 2.0f, (1080 - height) / 2.0f);
}

void CWorld::zoom(float factor) {
    scaleFactor *= factor;
    worldRect.setScale(scaleFactor, scaleFactor);
    worldRect.setPosition((1920 - (width * scaleFactor)) / 2.0f,
                          (1080 - (height * scaleFactor)) / 2.0f);
}

void CWorld::render(sf::RenderWindow& window) {
    window.clear(GameConfig::BACKGROUND_COLOR);
    window.draw(worldRect);
}

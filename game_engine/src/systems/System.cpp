/*
** EPITECH PROJECT, 2024
** B-CPP-500-TLS-5-2-rtype-anastasia.bouby
** File description:
** Implements the base `System` class and its render function, which handles
** the rendering of various components within the game engine.
** Responsibility:
** - Initialize and destroy the System class
** - Render entities by calling specific system functions for each component type
*/

#include "System.hpp"

GameEngine::System::System() {}

/**
 * @brief Renders the entities on the window.
 * 
 * This function renders the entities on the window by calling the spriteSystem, textSystem,
 * buttonSystem, buttonRectSystem, optionButtonSystem, sliderSystem, and shapeSystem functions.
 * 
 * @param window The render window where the entities will be drawn.
 * @param entities The map of entities to be rendered.
 */
void GameEngine::System::render(sf::RenderWindow& window,
                                std::map<int, Entity>& entities) {
    for (auto& [id, entity] : entities) {
        spriteSystem(window, entity);
        textSystem(window, entity);
        buttonSystem(window, entity);
        buttonRectSystem(window, entity);
        optionButtonSystem(window, entity);
        sliderSystem(window, entity, entities);
        shapeSystem(window, entity);
    }
}

GameEngine::System::~System() {}

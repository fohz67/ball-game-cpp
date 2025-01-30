/*
** EPITECH PROJECT, 2024
** B-CPP-500-TLS-5-2-rtype-anastasia.bouby
** File description:
** Implements the `Entity` class, which represents a game object.
** Each `Entity` can have various components attached to it, enabling it to
** have specific behaviors or properties.
** Responsibility:
** - Store an entity's unique ID
*/

#include "Entity.hpp"
#include <iostream>

/**
 * @brief Construct an Entity with an ID.
 *
 * This constructor initializes the entity with a given ID.
 *
 * @param id The ID of the entity.
 */
GameEngine::Entity::Entity(const int id) : _id(id) {}

/**
 * @brief Destructor for the Entity.
 *
 * This destructor cleans up any resources used by the entity.
 */
GameEngine::Entity::~Entity() {}

/**
 * @brief Get the ID of the Entity.
 *
 * This function retrieves the ID of the entity.
 *
 * @return The ID of the entity.
 */
int GameEngine::Entity::getEntityId() const {
    return (_id);
}

/**
 * @brief Display all components of the Entity.
 *
 * This function iterates over all components attached to the entity
 * and displays each one using its `display()` method.
 */
void GameEngine::Entity::displayComponents() const {
    for (auto& component : _components) {
        component.second->display();
    }
}

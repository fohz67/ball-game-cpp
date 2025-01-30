/*
** EPITECH PROJECT, 2024
** B-CPP-500-TLS-5-2-rtype-anastasia.bouby
** File description:
** Entity.hpp
*/

#pragma once

#include <memory>
#include <typeindex>
#include <unordered_map>
#include "components/Components.hpp"

namespace GameEngine {

class Entity {
  public:
    Entity() : _id(0) {}
    Entity(int id);

    template <typename... Args> Entity(int id, Args&&... args);

    ~Entity();

    template <typename ComponentType>
    void addComponent(const ComponentType& component);

    template <typename ComponentType> void removeComponent();

    template <typename ComponentType> ComponentType& getComponent();

    template <typename ComponentType> bool hasComponent() const;

    void displayComponents() const;
    int getEntityId() const;

  private:
    int _id;
    std::unordered_map<std::type_index, std::shared_ptr<Component>> _components;
};

/**
 * @brief Construct an Entity with an ID and optional components.
 *
 * This constructor initializes the entity with a given ID and adds components
 * to the entity. The components are forwarded as arguments to the
 * `addComponent` function.
 *
 * @tparam Args Types of the components to be added to the entity.
 * @param id The ID of the entity.
 * @param args The components to be added to the entity.
 *
 * @throws std::runtime_error If a component already exists in the entity.
 */
template <typename... Args>
Entity::Entity(const int id, Args&&... args) : _id(id) {
    (addComponent(std::forward<Args>(args)), ...);
}

/**
 * @brief Add a component to the Entity.
 *
 * This function adds a component to the current entity.
 * If the component already exists, an exception is thrown.
 *
 * @tparam ComponentType The type of the component.
 * @param component The component to be added to the entity.
 *
 * @throws std::runtime_error If the component already exists.
 */
template <typename ComponentType>
void Entity::addComponent(const ComponentType& component) {
    const auto component_found =
        _components.find(std::type_index(typeid(ComponentType)));
    if (component_found == _components.end()) {
        _components[std::type_index(typeid(ComponentType))] =
            std::make_shared<ComponentType>(component);
        return;
    }
    throw std::runtime_error(
        "GameEngine::Entity::addComponent: Component already exists");
}

/**
 * @brief Remove a component from the Entity.
 *
 * This function removes a specific component from the current entity.
 * If the component isn't found, an exception is thrown.
 *
 * @tparam ComponentType The type of the component.
 *
 * @throws std::runtime_error If the component is not found.
 */
template <typename ComponentType> void Entity::removeComponent() {
    const auto component_found =
        _components.find(std::type_index(typeid(ComponentType)));
    if (component_found == _components.end()) {
        throw std::runtime_error(
            "GameEngine::Entity::removeComponent: Component not found");
    }
    _components.erase(component_found);
}

/**
 * @brief Get a component from the Entity.
 *
 * This function retrieves a specific component from the current entity.
 * If the component isn't found, an exception is thrown.
 *
 * @tparam ComponentType The type of the component to retrieve.
 *
 * @return A reference to the requested component.
 *
 * @throws std::runtime_error If the component is not found.
 */
template <typename ComponentType> ComponentType& Entity::getComponent() {
    const auto component_found =
        _components.find(std::type_index(typeid(ComponentType)));
    if (component_found == _components.end()) {
        throw std::runtime_error(
            "GameEngine::Entity::getComponent: Component not found");
    }
    return static_cast<ComponentType&>(*component_found->second);
}

template <typename ComponentType> bool Entity::hasComponent() const {
    const auto component_found =
        _components.find(std::type_index(typeid(ComponentType)));
    if (component_found == _components.end()) {
        return false;
    }
    return true;
}

}; // namespace GameEngine
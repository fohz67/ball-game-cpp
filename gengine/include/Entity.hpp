#pragma once

#include <cstdint>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include "components/Components.hpp"

namespace GEngine {

class Entity {
  public:
    // Constructor / Destructor
    Entity();
    Entity(uint32_t id);
    ~Entity() = default;

    // Template methods
    template <typename... Args> Entity(uint32_t id, Args&&... args);
    template <typename ComponentType> void           addComponent(const ComponentType& component);
    template <typename ComponentType> void           removeComponent();
    template <typename ComponentType> ComponentType& getComponent();
    template <typename ComponentType> bool           hasComponent() const;

    // Methods
    void     displayComponents() const;
    uint32_t getEntityId() const;

  private:
    // Attributes
    uint32_t                                                        id;
    std::unordered_map<std::type_index, std::shared_ptr<Component>> components;
};

template <typename... Args> Entity::Entity(const uint32_t id, Args&&... args) : id(id) {
    (addComponent(std::forward<Args>(args)), ...);
}

template <typename ComponentType> void Entity::addComponent(const ComponentType& component) {
    const auto found = components.find(std::type_index(typeid(ComponentType)));

    if (found == components.end()) {
        components[std::type_index(typeid(ComponentType))] =
            std::make_shared<ComponentType>(component);
        return;
    }

    throw std::runtime_error("Component already exists");
}

template <typename ComponentType> void Entity::removeComponent() {
    const auto found = components.find(std::type_index(typeid(ComponentType)));

    if (found == components.end()) {
        throw std::runtime_error("Component not found");
    }

    components.erase(found);
}

template <typename ComponentType> ComponentType& Entity::getComponent() {
    const auto found = components.find(std::type_index(typeid(ComponentType)));

    if (found == components.end()) {
        throw std::runtime_error("Component not found");
    }

    return static_cast<ComponentType&>(*found->second);
}

template <typename ComponentType> bool Entity::hasComponent() const {
    return components.find(std::type_index(typeid(ComponentType))) != components.end();
}

}; // namespace GEngine

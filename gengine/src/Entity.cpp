#include "Entity.hpp"
#include <iostream>

GEngine::Entity::Entity() : id(0) {}

GEngine::Entity::Entity(const uint32_t id) : id(id) {}

uint32_t GEngine::Entity::getEntityId() const {
    return (id);
}

void GEngine::Entity::displayComponents() const {
    for (auto& component : components) {
        component.second->display();
    }
}

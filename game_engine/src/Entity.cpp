#include "Entity.hpp"

#include <iostream>

GameEngine::Entity::Entity() : id(0)
{
}

GameEngine::Entity::Entity(const uint32_t id) : id(id)
{
}

uint32_t GameEngine::Entity::getEntityId() const
{
    return (id);
}

void GameEngine::Entity::displayComponents() const
{
    for (auto& component : components)
    {
        component.second->display();
    }
}

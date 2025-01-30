#pragma once

#include <any>
#include <components/Color.hpp>
#include <components/Position.hpp>
#include <components/Shape.hpp>
#include <components/Sprite.hpp>
#include <components/Text.hpp>
#include <components/Texture.hpp>
#include <iostream>
#include <map>
#include <string>
#include "Entity.hpp"

class EntityManager {
  public:
    static EntityManager& get();
    void setEntities(std::map<int, GameEngine::Entity> entities);
    void createCell(int id, float x, float y, float radius, std::vector<double> color);
    void createWorld();
    void removeEntity(int id);
    void clearEntities();
    std::map<int, GameEngine::Entity>& getEntities();

  private:
    EntityManager() = default;
    ~EntityManager() = default;
    std::map<int, GameEngine::Entity> entities;
};

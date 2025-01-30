#pragma once

#include <any>
#include <iostream>
#include <map>
#include <mutex>
#include <string>
#include "Entity.hpp"

class EntityManager {
  public:
    static EntityManager& get();
    void setEntities(std::map<int, GameEngine::Entity> entities);
    void compareEntities(int id, std::map<std::string, std::any> components,
                         std::pair<float, float> updatePosition);
    void createEntity(int id, std::map<std::string, std::any> components);
    void removeEntity(int id);
    void clearEntities();
    std::map<int, GameEngine::Entity>& getEntities();

  private:
    EntityManager() = default;
    ~EntityManager() = default;
    std::map<int, GameEngine::Entity> entities;
    std::mutex mutex;
};

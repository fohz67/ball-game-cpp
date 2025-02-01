#pragma once

#include <map>
#include "Entity.hpp"

class EntityManager {
  public:
    EntityManager(const EntityManager&) = delete;
    EntityManager& operator=(const EntityManager&) = delete;

    static EntityManager& get();

    void createCell(uint32_t id, uint32_t ownedId, double x, double y,
                    double radius, std::vector<double> color);
    void createWorld(uint16_t size);

    std::map<int, GameEngine::Entity>& getEntities();
    void setEntities(std::map<int, GameEngine::Entity> entities);
    void clearEntities();
    void removeEntity(int id);

  private:
    EntityManager() = default;
    ~EntityManager() = default;

    std::map<int, GameEngine::Entity> entities;
};

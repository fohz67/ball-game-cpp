#pragma once

#include <map>
#include "Entity.hpp"

class EntityManager {
  public:
    EntityManager(const EntityManager&) = delete;
    EntityManager& operator=(const EntityManager&) = delete;

    static EntityManager& get();

    void createCell(uint32_t id, uint32_t ownerId, double x, double y,
                    double radius, std::vector<double> color);
    void updateCellPosition(uint32_t id, double x, double y);

    void createWorld(uint16_t size);

    std::map<int, GameEngine::Entity> entities;
    ;

  private:
    EntityManager() = default;
    ~EntityManager() = default;
};

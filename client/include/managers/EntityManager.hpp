#pragma once

#include <map>
#include <mutex>

#include "Entity.hpp"

class EntityManager
{
   public:
    EntityManager(const EntityManager&) = delete;
    EntityManager& operator=(const EntityManager&) = delete;

    static EntityManager& get();

    const void createCell(const uint32_t id,
                          const double x,
                          const double y,
                          const double radius,
                          std::vector<double> color,
                          const std::string& nickname);
    const void createNickname(const uint32_t id,
                              const double x,
                              const double y,
                              const double radius,
                              const std::string& nickname);
    const void createWorld(const uint16_t size);

    const void updateCell(const uint32_t id,
                          const double x,
                          const double y,
                          const double radius,
                          const bool isNickname);

    const void removeEntity(const double id);

    std::map<double, GameEngine::Entity> entities;
    std::map<double, GameEngine::Entity> hudEntities;

   private:
    EntityManager() = default;
    ~EntityManager() = default;

    std::map<double, int> linkedEntitiesBiases;
};

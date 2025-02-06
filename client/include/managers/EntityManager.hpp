#pragma once

#include <map>
#include "Entity.hpp"
#include "protocol/DataInterfaces.hpp"

class EntityManager {
  public:
    EntityManager(const EntityManager&)            = delete;
    EntityManager& operator=(const EntityManager&) = delete;

    static EntityManager& get();

    void createCell(uint32_t            id,
                    double              x,
                    double              y,
                    double              radius,
                    std::vector<double> color,
                    std::string         nickname);
    void createNickname(uint32_t id, double x, double y, double radius, std::string nickname);
    void createWorld(uint16_t size);

    void updateCell(uint32_t id, double x, double y, double radius, bool isNickname);

    void                              removeEntity(double id);
    std::map<double, GameEngine::Entity> getGameEntities() const;
    std::map<double, GameEngine::Entity> getHUDEntities() const;
    std::map<double, GameEngine::Entity> entities;

  private:
    EntityManager()  = default;
    ~EntityManager() = default;

    std::map<double, int> entitiesLinkingBiases;
};

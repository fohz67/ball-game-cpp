#pragma once

#include <map>
#include "Entity.hpp"
#include "protocol/DataInterfaces.hpp"

class EntityManager {
  public:
    EntityManager(const EntityManager&) = delete;
    EntityManager& operator=(const EntityManager&) = delete;

    static EntityManager& get();

    void createCell(uint32_t id, double x, double y, double radius,
                    std::vector<double> color, std::string nickname);
    void updateCell(uint32_t id, double x, double y, double radius,
                    bool isNickname);

    void createWorld(uint16_t size);

    void removeEntity(uint32_t id);

    std::map<int, GEngine::Entity> entities;

  private:
    EntityManager() = default;
    ~EntityManager() = default;
};

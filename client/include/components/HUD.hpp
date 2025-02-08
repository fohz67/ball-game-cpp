#pragma once

#include "config/ConfigClient.hpp"
#include "engine/GameClient.hpp"

class HUD
{
   public:
    HUD(const HUD&) = delete;
    HUD& operator=(const HUD&) = delete;

    static HUD& get();

    const void create();
    const void createLeaderboard();
    const void createStats();
    const void createChatBox();

    const void update();
    const void updateLeaderboard();
    const void updateStats();

    const void increaseId();

    const void setMass(const uint32_t mass);
    const void setScore(const uint32_t score);
    const void setCellCount(const uint32_t cellCount);

   private:
    HUD() = default;
    ~HUD() = default;

    double currentId = ConfigClient::World::ID;

    std::map<double, GameEngine::Entity> leaderboardEntities;
    std::map<double, GameEngine::Entity> statsEntity;
    std::map<double, GameEngine::Entity> chatBoxEntitites;

    uint32_t score = 0;
    uint32_t mass = 0;
    uint32_t cellCount = 0;
};

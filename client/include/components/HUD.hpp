#pragma once

#include "config/ConfigClient.hpp"
#include "engine/GameClient.hpp"

class HUD {
  public:
    HUD(const HUD&)            = delete;
    HUD& operator=(const HUD&) = delete;

    static HUD& get();

    const void create();
    const void createLeaderboard();
    const void createStats();
    const void createChatBox();

    const void update();
    const void updateStats();

    const void increaseId();

    const void setMass(const long mass);
    const void setScore(const long score);

  private:
    HUD()  = default;
    ~HUD() = default;

    double currentId = ConfigClient::World::ID;

    std::map<double, GameEngine::Entity> leaderboardEntities;
    std::map<double, GameEngine::Entity> statsEntity;
    std::map<double, GameEngine::Entity> chatBoxEntitites;

    long score = 0;
    long mass  = 0;
};

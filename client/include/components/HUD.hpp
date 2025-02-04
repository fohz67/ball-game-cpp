#pragma once

#include "config/ConfigClient.hpp"
#include "engine/GameClient.hpp"

class HUD {
  public:
    HUD(const HUD&)            = delete;
    HUD& operator=(const HUD&) = delete;

    static HUD& get();

    void create();
    void createLeaderboard();
    void createStats();
    void createChatBox();

    void increaseId();

    void setMass(long mass);
    void setScore(long score);

  private:
    HUD()  = default;
    ~HUD() = default;

    double currentId = ConfigClient::World::ID;

    std::map<double, GEngine::Entity> leaderboardEntities;
    std::map<double, GEngine::Entity> statsEntity;
    std::map<double, GEngine::Entity> chatBoxEntitites;
};

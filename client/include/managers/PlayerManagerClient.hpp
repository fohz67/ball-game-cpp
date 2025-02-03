#pragma once

#include <vector>
#include "components/PlayerClient.hpp"

class PlayerManagerClient {
  public:
    PlayerManagerClient(const PlayerManagerClient&) = delete;
    PlayerManagerClient& operator=(const PlayerManagerClient&) = delete;

    static PlayerManagerClient& get();

    void removePlayer(uint32_t playerId);
    PlayerClient* getPlayer(uint32_t playerId);

  private:
    PlayerManagerClient() = default;
    ~PlayerManagerClient() = default;

    std::vector<PlayerClient> players;
};

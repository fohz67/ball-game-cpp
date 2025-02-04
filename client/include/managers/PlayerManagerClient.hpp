#pragma once

#include <vector>
#include "components/PlayerClient.hpp"

class PlayerManagerClient {
  public:
    PlayerManagerClient(const PlayerManagerClient&)            = delete;
    PlayerManagerClient& operator=(const PlayerManagerClient&) = delete;

    static PlayerManagerClient& get();

    void removePlayer(uint32_t playerId);

    PlayerClient* getPlayer(uint32_t playerId);
    PlayerClient* getMe();
    uint32_t      getMyId();

    void setMyId(uint32_t id);

    std::vector<PlayerClient> players;

  private:
    PlayerManagerClient()  = default;
    ~PlayerManagerClient() = default;

    uint32_t myId;
};

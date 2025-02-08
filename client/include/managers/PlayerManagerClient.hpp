#pragma once

#include <vector>

#include "components/PlayerClient.hpp"

class PlayerManagerClient
{
   public:
    PlayerManagerClient(const PlayerManagerClient&) = delete;
    PlayerManagerClient& operator=(const PlayerManagerClient&) = delete;

    static PlayerManagerClient& get();

    const void addPlayer(const uint32_t id,
                         const std::string& nickname,
                         const std::vector<double> color,
                         const std::vector<double> cellColor);

    const void removePlayer(const uint32_t playerId);

    PlayerClient* getPlayer(const uint32_t playerId);
    std::vector<PlayerClient> getPlayers() const;

   private:
    PlayerManagerClient() = default;
    ~PlayerManagerClient() = default;

    std::vector<PlayerClient> players;
    uint32_t myId;
};

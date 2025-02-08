#include "managers/PlayerManagerClient.hpp"

#include <algorithm>

PlayerManagerClient& PlayerManagerClient::get()
{
    static PlayerManagerClient instance;
    return instance;
}

const void PlayerManagerClient::removePlayer(const uint32_t playerId)
{
    players.erase(
        std::remove_if(players.begin(),
                       players.end(),
                       [playerId](const PlayerClient& p) { return p.getId() == playerId; }),
        players.end());
}

PlayerClient* PlayerManagerClient::getPlayer(const uint32_t playerId)
{
    for (PlayerClient& player : players)
    {
        if (player.getId() == playerId)
        {
            return &player;
        }
    }

    return nullptr;
}

#include "managers/PlayerManagerClient.hpp"

#include <algorithm>

PlayerManagerClient& PlayerManagerClient::get()
{
    static PlayerManagerClient instance;
    return instance;
}

const void PlayerManagerClient::addPlayer(const uint32_t id,
                                          const std::string& nickname,
                                          const std::vector<double>& color,
                                          const std::vector<double>& cellColor)
{
    players.emplace_back(id, nickname, color, cellColor);
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

std::vector<PlayerClient> PlayerManagerClient::getPlayers() const
{
    return players;
}

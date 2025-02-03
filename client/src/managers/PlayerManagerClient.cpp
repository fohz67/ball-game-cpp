#include "managers/PlayerManagerClient.hpp"

PlayerManagerClient& PlayerManagerClient::get() {
    static PlayerManagerClient instance;
    return instance;
}

void PlayerManagerClient::removePlayer(uint32_t playerId) {
    players.erase(std::remove_if(players.begin(), players.end(),
                                 [playerId](const PlayerClient& p) {
                                     return p.getId() == playerId;
                                 }),
                  players.end());
}

PlayerClient* PlayerManagerClient::getPlayer(uint32_t playerId) {
    for (auto& player : players) {
        if (player.getId() == playerId) {
            return &player;
        }
    }

    return nullptr;
}

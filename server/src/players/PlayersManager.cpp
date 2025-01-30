#include "players/PlayersManager.hpp"
#include "game_components/cells/CellsManager.hpp"

PlayersManager& PlayersManager::get() {
    static PlayersManager instance;
    return instance;
}

Player&
PlayersManager::addPlayer(std::shared_ptr<asio::ip::tcp::socket> client) {
    uint32_t playerId = nextPlayerId++;
    players.emplace_back(playerId, client);
    CellsManager::get().createRandomCell(playerId);
    return players.back();
}

void PlayersManager::removePlayer(uint32_t playerId) {
    players.erase(std::remove_if(players.begin(), players.end(),
                                 [playerId](const Player& p) {
                                     return p.getId() == playerId;
                                 }),
                  players.end());
    CellsManager::get().removeCellsByPlayer(playerId);
}

Player* PlayersManager::getPlayer(uint32_t playerId) {
    for (auto& player : players) {
        if (player.getId() == playerId) {
            return &player;
        }
    }
    return nullptr;
}

Player* PlayersManager::getPlayerByClient(
    std::shared_ptr<asio::ip::tcp::socket> client) {
    for (auto& player : players) {
        if (player.getClient() == client) {
            return &player;
        }
    }
    return nullptr;
}

const std::vector<Player>& PlayersManager::getAllPlayers() const {
    return players;
}

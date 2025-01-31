#include "player/PlayerManager.hpp"
#include "cell/CellManager.hpp"

PlayerManager& PlayerManager::get() {
    static PlayerManager instance;
    return instance;
}

Player&
PlayerManager::addPlayer(std::shared_ptr<asio::ip::tcp::socket> client) {
    uint32_t playerId = nextPlayerId++;
    players.emplace_back(playerId, client);
    CellManager::get().createCell(playerId);
    return players.back();
}

void PlayerManager::removePlayer(uint32_t playerId) {
    players.erase(std::remove_if(players.begin(), players.end(),
                                 [playerId](const Player& p) {
                                     return p.getId() == playerId;
                                 }),
                  players.end());
    CellManager::get().removePlayerCells(playerId);
}

Player* PlayerManager::getPlayer(uint32_t playerId) {
    for (auto& player : players) {
        if (player.getId() == playerId) {
            return &player;
        }
    }
    return nullptr;
}

Player* PlayerManager::getPlayerByClient(
    std::shared_ptr<asio::ip::tcp::socket> client) {
    for (auto& player : players) {
        if (player.getClient() == client) {
            return &player;
        }
    }
    return nullptr;
}

const std::vector<Player>& PlayerManager::getAllPlayers() const {
    return players;
}

void PlayerManager::updatePlayers() {
    for (auto& player : players) {
        auto cells = CellManager::get().getPlayerCells(player.getId());

        std::pair<float, float> positions = player.getMousePosition();
        CellManager::get().updateCellMovement(player.getId(), positions.first, positions.second);

        std::pair<float, float> newViewport =
            CellManager::get().calculateViewport(player.getId());
        player.setViewport(newViewport.first, newViewport.second);
    }
}

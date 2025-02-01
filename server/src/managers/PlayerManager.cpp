#include "managers/PlayerManager.hpp"
#include "managers/AtomicIdsManager.hpp"
#include "managers/CellManager.hpp"

PlayerManager& PlayerManager::get() {
    static PlayerManager instance;
    return instance;
}

Player&
PlayerManager::addPlayer(std::shared_ptr<asio::ip::tcp::socket> client) {
    uint32_t playerId = AtomicIdsManager::get().getNextId();

    players.emplace_back(playerId, client);
    CellManager::get().createCell(playerId, CellType::PLAYER);

    return players.back();
}

void PlayerManager::removePlayer(uint32_t playerId) {
    players.erase(std::remove_if(players.begin(), players.end(),
                                 [playerId](const Player& p) {
                                     return p.getId() == playerId;
                                 }),
                  players.end());

    CellManager::get().removeCellsFromId(playerId);
    AtomicIdsManager::get().removeId(playerId);
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

std::vector<Player>& PlayerManager::getAllPlayers() {
    return players;
}

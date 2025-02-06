#include "managers/PlayerManager.hpp"
#include "config/Config.hpp"
#include "engine/Game.hpp"
#include "managers/CellManager.hpp"
#include "protocol/Send.hpp"
#include "util/AtomicID.hpp"
#include "util/Util.hpp"

PlayerManager& PlayerManager::get() {
    static PlayerManager instance;
    return instance;
}

const void PlayerManager::newPlayer(const std::shared_ptr<asio::ip::tcp::socket> client) {
    const uint32_t            playerId      = AtomicID::get().getNextId();
    const std::vector<double> nicknameColor = Config::Gameplay::Player::COLOR;
    const std::vector<double> cellColor     = Util::getRandomColor();

    players.emplace_back(playerId, client, nicknameColor, cellColor);
}

const void PlayerManager::removePlayer(const std::shared_ptr<asio::ip::tcp::socket> client) {
    for (auto it = players.begin(); it != players.end(); ++it) {
        if (it->getClient() == client) {
            uint32_t id = it->getId();

            players.erase(it);

            Send::sendPlayerDeleted(id);
            CellManager::get().removeCells(id);
            AtomicID::get().removeId(id);

            break;
        }
    }
}

Player* PlayerManager::getPlayer(const std::shared_ptr<asio::ip::tcp::socket> client) {
    for (Player& player : players) {
        if (player.getClient() == client) {
            return &player;
        }
    }

    return nullptr;
}

std::vector<Player>& PlayerManager::getPlayers() {
    return players;
}

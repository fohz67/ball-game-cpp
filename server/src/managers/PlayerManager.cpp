#include "managers/PlayerManager.hpp"

#include "config/Config.hpp"
#include "managers/CellManager.hpp"
#include "protocol/Send.hpp"
#include "util/AtomicID.hpp"
#include "util/Util.hpp"

PlayerManager& PlayerManager::get()
{
    static PlayerManager instance;
    return instance;
}

const void PlayerManager::newPlayer(const std::shared_ptr<asio::ip::tcp::socket>& client)
{
    uint32_t playerId = AtomicID::get().getNextId();
    const std::vector<double> nicknameColor = Config::Gameplay::Player::COLOR;
    const std::vector<double> cellColor = Util::getRandomColor();

    players.emplace(client, Player(playerId, client, nicknameColor, cellColor));
}

const void PlayerManager::removePlayer(const std::shared_ptr<asio::ip::tcp::socket>& client)
{
    auto it = players.find(client);

    if (it != players.end())
    {
        uint32_t id = it->second.getId();

        players.erase(it);

        Send::sendPlayerDeleted(id);
        CellManager::get().removeCells(id);
        AtomicID::get().removeId(id);
    }
}

Player* PlayerManager::getPlayer(const std::shared_ptr<asio::ip::tcp::socket>& client)
{
    auto it = players.find(client);
    return (it != players.end()) ? &it->second : nullptr;
}

std::vector<Player*> PlayerManager::getPlayers()
{
    std::vector<Player*> result;

    result.reserve(players.size());

    for (auto& pair : players)
    {
        result.push_back(&pair.second);
    }

    return result;
}

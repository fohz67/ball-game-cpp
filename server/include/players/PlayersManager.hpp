#pragma once

#include <asio.hpp>
#include <memory>
#include <vector>
#include "Player.hpp"

class PlayersManager {
  public:
    PlayersManager(const PlayersManager&) = delete;
    PlayersManager& operator=(const PlayersManager&) = delete;
    static PlayersManager& get();
    Player& addPlayer(std::shared_ptr<asio::ip::tcp::socket> client);
    void removePlayer(uint32_t playerId);
    Player* getPlayer(uint32_t playerId);
    Player* getPlayerByClient(std::shared_ptr<asio::ip::tcp::socket> client);
    const std::vector<Player>& getAllPlayers() const;

  private:
    PlayersManager() = default;
    ~PlayersManager() = default;
    uint32_t nextPlayerId = 1;
    std::vector<Player> players;
};

#pragma once

#include <asio.hpp>
#include <memory>
#include <vector>
#include "Player.hpp"

class PlayerManager {
  public:
    PlayerManager(const PlayerManager&) = delete;
    PlayerManager& operator=(const PlayerManager&) = delete;
    static PlayerManager& get();
    Player& addPlayer(std::shared_ptr<asio::ip::tcp::socket> client);
    void removePlayer(uint32_t playerId);
    Player* getPlayer(uint32_t playerId);
    Player* getPlayerByClient(std::shared_ptr<asio::ip::tcp::socket> client);
    const std::vector<Player>& getAllPlayers() const;

  private:
    PlayerManager() = default;
    ~PlayerManager() = default;
    uint32_t nextPlayerId = 1;
    std::vector<Player> players;
};

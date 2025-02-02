#pragma once

#include <asio.hpp>
#include <memory>
#include <vector>
#include "components/Player.hpp"

class PlayerManager {
  public:
    PlayerManager(const PlayerManager&) = delete;
    PlayerManager& operator=(const PlayerManager&) = delete;

    static PlayerManager& get();

    void updatePlayers();

    Player& addPlayer(std::shared_ptr<asio::ip::tcp::socket> client);
    void removePlayer(uint32_t playerId);

    Player* getPlayerByClient(std::shared_ptr<asio::ip::tcp::socket> client);
    std::vector<Player>& getAllPlayers();

  private:
    PlayerManager() = default;
    ~PlayerManager() = default;

    std::vector<Player> players;
};

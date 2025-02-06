#pragma once

#include <asio.hpp>
#include <memory>
#include <vector>
#include "components/Player.hpp"

class PlayerManager {
  public:
    PlayerManager(const PlayerManager&)            = delete;
    PlayerManager& operator=(const PlayerManager&) = delete;

    static PlayerManager& get();

    const void updatePlayers();

    const void addPlayer(const std::shared_ptr<asio::ip::tcp::socket> client);
    const void removePlayer(const std::shared_ptr<asio::ip::tcp::socket> client);
    Player*    getPlayer(const std::shared_ptr<asio::ip::tcp::socket> client);

    std::vector<Player>& getPlayers();

  private:
    PlayerManager()  = default;
    ~PlayerManager() = default;

    std::vector<Player> players;
};

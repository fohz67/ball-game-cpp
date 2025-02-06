#pragma once

#include <asio.hpp>
#include <memory>
#include <unordered_map>
#include <vector>
#include "components/Player.hpp"

class PlayerManager {
  public:
    PlayerManager(const PlayerManager&)            = delete;
    PlayerManager& operator=(const PlayerManager&) = delete;

    static PlayerManager& get();

    const void           newPlayer(const std::shared_ptr<asio::ip::tcp::socket>& client);
    const void           removePlayer(const std::shared_ptr<asio::ip::tcp::socket>& client);
    Player*              getPlayer(const std::shared_ptr<asio::ip::tcp::socket>& client);
    std::vector<Player*> getPlayers();

  private:
    PlayerManager()  = default;
    ~PlayerManager() = default;

    std::unordered_map<std::shared_ptr<asio::ip::tcp::socket>, Player> players;
};

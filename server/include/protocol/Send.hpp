#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <memory>
#include "components/Player.hpp"

class Send {
  public:
    static const void sendWorld(const std::shared_ptr<asio::ip::tcp::socket> client);
    static const void sendPlayer(const Player& player);
    static const void sendPlayers(const std::shared_ptr<asio::ip::tcp::socket> client);
    static const void sendCells();
    static const void sendPellets(const std::shared_ptr<asio::ip::tcp::socket> client);
    static const void sendViewport();
    static const void sendEntityRemoved(const std::vector<uint32_t>& deletedCellsIds);
    static const void sendPlayerDeleted(const uint32_t playerId);
    static const void sendMe(const std::shared_ptr<asio::ip::tcp::socket> client);
};

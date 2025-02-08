#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <memory>

#include "components/Player.hpp"

class Send
{
   public:
    static const void sendWorld(const std::shared_ptr<asio::ip::tcp::socket>& client);
    static const void sendPlayer(const Player* player);
    static const void sendPlayers(const std::shared_ptr<asio::ip::tcp::socket>& client);
    static const void sendUpdateGameState();
    static const void sendPellets(const std::shared_ptr<asio::ip::tcp::socket>& client);
    static const void sendPellet(const uint32_t pelletId,
                                 const Vector2& location,
                                 const double radius,
                                 const std::vector<double> color);
    static const void sendUpdatePlayer();
    static const void sendEntityRemoved(const std::vector<uint32_t>& deletedCellsIds);
    static const void sendPlayerDeleted(const uint32_t playerId);
    static const void sendUpdateLeaderboard();
};

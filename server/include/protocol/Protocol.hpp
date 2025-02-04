#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <memory>
#include "components/Cell.hpp"
#include "components/Player.hpp"

class Protocol {
  public:
    Protocol(const Protocol&)            = delete;
    Protocol& operator=(const Protocol&) = delete;

    static Protocol& get();

    void injector(char* buffer, size_t length, SmartBuffer& smartBuffer);

    void handleMessage(std::shared_ptr<asio::ip::tcp::socket> client, SmartBuffer& smartBuffer);

    void sendPlayer(const Player& player);
    void sendPlayers(std::shared_ptr<asio::ip::tcp::socket> client);
    void sendCells();
    void sendPellets(std::shared_ptr<asio::ip::tcp::socket> client);
    void sendViewport();
    void sendEntityRemoved(const std::vector<uint32_t>& deletedCellsIds);
    void sendPlayerDeleted(uint32_t playerId);

  private:
    Protocol()  = default;
    ~Protocol() = default;
};

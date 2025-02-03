#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <memory>
#include "components/Cell.hpp"

class Protocol {
  public:
    Protocol(const Protocol&) = delete;
    Protocol& operator=(const Protocol&) = delete;

    static Protocol& get();

    void injector(char* buffer, size_t length, SmartBuffer& smartBuffer);

    void handleMessage(std::shared_ptr<asio::ip::tcp::socket> client,
                       SmartBuffer& smartBuffer);

    void sendCells(CellType type);
    void sendViewport();
    void sendEntityRemoved(const std::vector<uint32_t>& deletedCellsIds);

  private:
    Protocol() = default;
    ~Protocol() = default;
};

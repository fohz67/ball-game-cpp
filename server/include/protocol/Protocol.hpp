#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <memory>

class Protocol {
  public:
    Protocol(const Protocol&) = delete;
    Protocol& operator=(const Protocol&) = delete;

    static Protocol& get();

    void injector(char* buffer, size_t length, SmartBuffer& smartBuffer);

    void handleMessage(std::shared_ptr<asio::ip::tcp::socket> client,
                       SmartBuffer& smartBuffer);

    void sendGameState();
    void sendViewport();

  private:
    Protocol() = default;
    ~Protocol() = default;
};

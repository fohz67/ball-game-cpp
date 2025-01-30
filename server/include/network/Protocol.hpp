#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <iostream>

class Protocol {
  public:
    Protocol(const Protocol&) = delete;
    Protocol& operator=(const Protocol&) = delete;
    static Protocol& get();
    static void injector(char* buffer, size_t length, SmartBuffer& smartBuffer);
    static void handle_message(std::shared_ptr<asio::ip::tcp::socket> client,
                               SmartBuffer& smartBuffer);

  private:
    Protocol() = default;
    ~Protocol() = default;
};

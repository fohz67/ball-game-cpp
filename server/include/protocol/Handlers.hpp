#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>

class Handlers {
  public:
    static void handleJoin(std::shared_ptr<asio::ip::tcp::socket> client,
                           SmartBuffer& smartBuffer);
    static void
    handleMousePosition(std::shared_ptr<asio::ip::tcp::socket> client,
                        SmartBuffer& smartBuffer);
    static void handleKeyPressed(std::shared_ptr<asio::ip::tcp::socket> client,
                                 SmartBuffer& smartBuffer);
};

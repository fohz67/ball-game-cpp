#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>

class Read {
  public:
    static const void readPing(const std::shared_ptr<asio::ip::tcp::socket> client,
                               SmartBuffer&                                 smartBuffer);
    static const void readJoin(const std::shared_ptr<asio::ip::tcp::socket> client,
                               SmartBuffer&                                 smartBuffer);
    static const void readMousePosition(const std::shared_ptr<asio::ip::tcp::socket> client,
                                        SmartBuffer&                                 smartBuffer);
    static const void readKeyPressed(const std::shared_ptr<asio::ip::tcp::socket> client,
                                     SmartBuffer&                                 smartBuffer);
};

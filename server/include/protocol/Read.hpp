#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>

class Read
{
   public:
    static const void readPingPong(const std::shared_ptr<asio::ip::tcp::socket>& client,
                                   SmartBuffer& smartBuffer);
    static const void readJoinServer(const std::shared_ptr<asio::ip::tcp::socket>& client,
                                     SmartBuffer& smartBuffer);
    static const void readUpdateMousePosition(const std::shared_ptr<asio::ip::tcp::socket>& client,
                                              SmartBuffer& smartBuffer);
};

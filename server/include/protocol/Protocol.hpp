#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <memory>

class Protocol
{
   public:
    Protocol(const Protocol&) = delete;
    Protocol& operator=(const Protocol&) = delete;

    static Protocol& get();

    const void injector(char* buffer, const size_t length, SmartBuffer& smartBuffer);
    const void handleMessage(const std::shared_ptr<asio::ip::tcp::socket>& client,
                             SmartBuffer& smartBuffer);

   private:
    Protocol() = default;
    ~Protocol() = default;
};

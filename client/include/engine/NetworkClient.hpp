#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <cstdint>
#include <thread>

class NetworkClient
{
   public:
    NetworkClient(const NetworkClient&) = delete;
    NetworkClient& operator=(const NetworkClient&) = delete;

    static NetworkClient& get();

    const void init(const std::string ip, const unsigned short port);
    const void stop();
    const void run();
    const void send(SmartBuffer& smartBuffer);

    uint32_t getCutPacketSize(SmartBuffer smartBuffer, const uint32_t size) const;
    uint64_t getPing() const;

    const void setPing(const uint64_t newPing);

   private:
    NetworkClient();
    ~NetworkClient();

    const void receive();

    asio::io_context io_context;
    asio::ip::tcp::socket socket;
    std::string host;
    unsigned short port;
    std::thread networkThread;
    uint64_t ping = 0;
    bool running = true;
};

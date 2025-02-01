#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <thread>

#define MAX_BUFFER_SIZE 1024

class NetworkClient {
  public:
    NetworkClient(const NetworkClient&) = delete;
    NetworkClient& operator=(const NetworkClient&) = delete;

    static NetworkClient& get();

    void init(std::string ip, unsigned short port);
    void run();
    void send(SmartBuffer& smartBuffer);

  private:
    NetworkClient();
    ~NetworkClient() = default;

    void receive();

    asio::io_context io_context;
    asio::ip::tcp::socket socket;
    std::string host;
    unsigned short port;
};

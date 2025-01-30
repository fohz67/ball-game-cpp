#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <iostream>
#include <string>
#include <thread>

#define MAX_BUFFER_SIZE 1024

class CNetwork {
  public:
    CNetwork(const CNetwork&) = delete;
    CNetwork& operator=(const CNetwork&) = delete;
    static CNetwork& get();
    void init(std::string ip, unsigned short port);
    void run();
    void send(SmartBuffer& smartBuffer);

  private:
    CNetwork();
    ~CNetwork() = default;
    void receive();
    asio::io_context io_context;
    asio::ip::tcp::socket socket;
    std::string host;
    unsigned short port;
    std::thread network_thread;
};

#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <iostream>
#include <string>
#include <thread>

#define MAX_BUFFER_SIZE 1024

class CNetwork {
  public:
    CNetwork(const std::string& host, unsigned short port);
    void run();
    void send(SmartBuffer& smartBuffer);

  private:
    void receive();

    asio::io_context io_context;
    asio::ip::tcp::socket socket;
    std::string host;
    unsigned short port;
    std::thread network_thread;
};

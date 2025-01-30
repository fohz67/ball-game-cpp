#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <unordered_map>

#define MAX_BUFFER_SIZE 1024

class Network {
  public:
    Network(const Network&) = delete;
    Network& operator=(const Network&) = delete;
    static Network& get();
    void run();
    void sendToClient(std::shared_ptr<asio::ip::tcp::socket> client,
                        SmartBuffer& smartBuffer);
    void sendToAll(SmartBuffer& smartBuffer);

  private:
    Network();
    ~Network() = default;
    void doAccept();
    void handleClient(std::shared_ptr<asio::ip::tcp::socket> socket);
    void sendLoop();
    asio::io_context io_context;
    asio::ip::tcp::acceptor acceptor;
    std::unordered_map<std::shared_ptr<asio::ip::tcp::socket>, uint32_t>
        clients;
    std::thread sendThread;
};

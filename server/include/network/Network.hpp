#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <unordered_set>

#define MAX_BUFFER_SIZE 1024

class Network {
  public:
    Network(const Network&) = delete;
    Network& operator=(const Network&) = delete;
    static Network& get();
    void run();
    short get_port() const {
        return port;
    }
    void send_to_client(std::shared_ptr<asio::ip::tcp::socket> client,
                        SmartBuffer& smartBuffer);
    void send_to_all(SmartBuffer& smartBuffer);

  private:
    Network();
    ~Network() = default;
    void do_accept();
    void handle_client(std::shared_ptr<asio::ip::tcp::socket> socket);
    asio::io_context io_context;
    asio::ip::tcp::acceptor acceptor;
    unsigned short port;
    std::unordered_set<std::shared_ptr<asio::ip::tcp::socket>> clients;
};

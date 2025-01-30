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
    void send_to_client(std::shared_ptr<asio::ip::tcp::socket> client,
                        SmartBuffer& smartBuffer);
    void send_to_all(SmartBuffer& smartBuffer);

  private:
    Network();
    ~Network() = default;
    void do_accept();
    void handle_client(std::shared_ptr<asio::ip::tcp::socket> socket);
    void send_loop();
    asio::io_context io_context;
    asio::ip::tcp::acceptor acceptor;
    std::unordered_map<std::shared_ptr<asio::ip::tcp::socket>, uint32_t>
        clients;
    std::thread sendThread;
};

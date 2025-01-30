// Network.hpp
#pragma once

#include <asio.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <unordered_set>
#include <memory>
#include "SmartBuffer.hpp"
#include "OpCodes.hpp"
#include "Protocol.hpp"

class Network {
public:
    Network(unsigned short port);
    void start();
    short get_port() const { return port; }
    void send_to_client(std::shared_ptr<asio::ip::tcp::socket> client, SmartBuffer& smartBuffer);
    void send_to_all(SmartBuffer& smartBuffer);

private:
    void do_accept();
    void handle_client(std::shared_ptr<asio::ip::tcp::socket> socket);

    asio::io_context io_context;
    asio::ip::tcp::acceptor acceptor;
    unsigned short port;
    std::unordered_set<std::shared_ptr<asio::ip::tcp::socket>> clients;
};

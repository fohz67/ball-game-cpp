#pragma once

#include <SmartBuffer.hpp>
#include <asio.hpp>
#include <memory>
#include <thread>

class Network {
  public:
    Network(const Network&)            = delete;
    Network& operator=(const Network&) = delete;

    static Network& get();

    void run();

    void prepare(std::shared_ptr<asio::ip::tcp::socket> socket,
                 std::shared_ptr<std::vector<char>>     buffer,
                 std::size_t                            length);

    void sendToClient(std::shared_ptr<asio::ip::tcp::socket> client, SmartBuffer& smartBuffer);
    void sendToAll(SmartBuffer& smartBuffer);

  private:
    Network();
    ~Network() = default;

    void doAccept();
    void newClient(std::shared_ptr<asio::ip::tcp::socket> socket);
    void sendLoop();

    asio::io_context        io_context;
    asio::ip::tcp::acceptor acceptor;
    std::thread             sendThread;
};

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

    const void run();

    const void sendToClient(const std::shared_ptr<asio::ip::tcp::socket> client,
                            SmartBuffer&                                 smartBuffer);
    const void sendToAll(SmartBuffer& smartBuffer);

  private:
    Network();
    ~Network() = default;

    const void asyncAccept();
    const void asyncRead(const std::shared_ptr<asio::ip::tcp::socket> socket);
    const void sendLoop();

    asio::io_context        io_context;
    asio::ip::tcp::acceptor acceptor;
    std::thread             sendThread;
};

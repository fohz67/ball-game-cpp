#include "Network.hpp"
#include "Protocol.hpp"

Network::Network(unsigned short port)
    : acceptor(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)),
      port(port) {}

void Network::start() {
    do_accept();
    io_context.run();
}

void Network::do_accept() {
    acceptor.async_accept(
        [this](std::error_code ec, asio::ip::tcp::socket socket) {
            if (!ec) {
                std::cout << "New connection from: " << socket.remote_endpoint()
                          << std::endl;
                auto client_socket =
                    std::make_shared<asio::ip::tcp::socket>(std::move(socket));
                clients.insert(client_socket);
                handle_client(client_socket);
            }
            do_accept();
        });
}

void Network::handle_client(std::shared_ptr<asio::ip::tcp::socket> socket) {
    auto buffer = std::make_shared<std::vector<char>>(MAX_BUFFER_SIZE);

    socket->async_read_some(
        asio::buffer(*buffer),
        [this, socket, buffer](std::error_code ec, std::size_t length) {
            if (!ec) {
                SmartBuffer smartBuffer;
                Protocol::injector(buffer->data(), length, smartBuffer);
                Protocol::handle_message(*this, socket, smartBuffer);
                this->handle_client(socket);
            } else {
                clients.erase(socket);
                std::cerr << "Client disconnected: "
                          << socket->remote_endpoint() << std::endl;
            }
        });
}

void Network::send_to_client(std::shared_ptr<asio::ip::tcp::socket> client,
                             SmartBuffer& smartBuffer) {
    if (clients.find(client) != clients.end()) {
        asio::write(*client, asio::buffer(smartBuffer.getBuffer(),
                                          smartBuffer.getSize()));
    }
}

void Network::send_to_all(SmartBuffer& smartBuffer) {
    for (auto& client : clients) {
        asio::write(*client, asio::buffer(smartBuffer.getBuffer(),
                                          smartBuffer.getSize()));
    }
}

#include "engine/NetworkClient.hpp"
#include <iostream>
#include "protocol/ProtocolClient.hpp"

NetworkClient& NetworkClient::get() {
    static NetworkClient instance;
    return instance;
}

NetworkClient::NetworkClient() : socket(io_context) {}

void NetworkClient::init(std::string ip, unsigned short port) {
    this->host = ip;
    this->port = port;
}

void NetworkClient::run() {
    try {
        asio::ip::tcp::resolver resolver(io_context);
        asio::ip::tcp::resolver::results_type endpoints =
            resolver.resolve(host, std::to_string(port));

        asio::connect(socket, endpoints);

        std::cout << "Connected to server: " << host << ":" << port
                  << std::endl;

        networkThread = std::thread(&NetworkClient::receive, this);
    } catch (const std::exception& e) {
        std::cerr << "Network connection error: " << e.what() << std::endl;
    }
}

void NetworkClient::send(SmartBuffer& smartBuffer) {
    try {
        asio::write(socket, asio::buffer(smartBuffer.getBuffer(),
                                         smartBuffer.getSize()));
    } catch (const std::exception& e) {
        std::cerr << "Send error: " << e.what() << std::endl;
    }
}

void NetworkClient::receive() {
    SmartBuffer smartBuffer;

    try {
        while (true) {
            char buffer[MAX_BUFFER_SIZE];
            asio::error_code error;
            size_t length = socket.read_some(asio::buffer(buffer), error);

            if (error == asio::error::eof) {
                std::cerr << "Server disconnected." << std::endl;
                return;
            } else if (error) {
                throw asio::system_error(error);
            }

            ProtocolClient::get().injector(buffer, length, smartBuffer);
            ProtocolClient::get().handleMessage(smartBuffer);
        }
    } catch (const std::exception& e) {
        std::cerr << "Receive error: " << e.what() << std::endl;
    }
}

#include "engine/NetworkClient.hpp"
#include <iostream>
#include "config/ConfigClient.hpp"
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
            asio::error_code error;

            uint32_t packetSize;
            asio::read(socket, asio::buffer(&packetSize, sizeof(packetSize)),
                       error);
            if (error) {
                throw asio::system_error(error);
            }

            std::vector<uint8_t> buffer(packetSize);
            asio::read(socket, asio::buffer(buffer.data(), packetSize), error);
            if (error) {
                throw asio::system_error(error);
            }

            smartBuffer.reset();
            smartBuffer.inject(buffer.data(), packetSize);

            ProtocolClient::get().handleMessage(smartBuffer);
        }
    } catch (const std::exception& e) {
        std::cerr << "Receive error: " << e.what() << std::endl;
    }
}

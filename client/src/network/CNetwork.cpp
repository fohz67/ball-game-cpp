#include "network/CNetwork.hpp"
#include "network/CProtocol.hpp"

CNetwork& CNetwork::get() {
    static CNetwork instance;
    return instance;
}

CNetwork::CNetwork() : socket(io_context) {} 

void CNetwork::init(std::string ip, unsigned short port) {
    this->host = ip;
    this->port = port;
}

void CNetwork::run() {
    try {
        asio::ip::tcp::resolver resolver(io_context);
        asio::ip::tcp::resolver::results_type endpoints =
            resolver.resolve(host, std::to_string(port));
        asio::connect(socket, endpoints);
        std::cout << "Connected to server: " << host << ":" << port
                  << std::endl;

        network_thread = std::thread(&CNetwork::receive, this);
    } catch (const std::exception& e) {
        std::cerr << "Network connection error: " << e.what() << std::endl;
    }
}

void CNetwork::send(SmartBuffer& smartBuffer) {
    try {
        asio::write(socket, asio::buffer(smartBuffer.getBuffer(),
                                         smartBuffer.getSize()));
    } catch (const std::exception& e) {
        std::cerr << "Send error: " << e.what() << std::endl;
    }
}

void CNetwork::receive() {
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

            CProtocol::get().injector(buffer, length, smartBuffer);
            CProtocol::get().handle_message(smartBuffer);
        }
    } catch (const std::exception& e) {
        std::cerr << "Receive error: " << e.what() << std::endl;
    }
}

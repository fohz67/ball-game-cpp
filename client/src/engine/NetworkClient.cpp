#include "engine/NetworkClient.hpp"

#include <iostream>

#include "config/ConfigClient.hpp"
#include "protocol/OpCodes.hpp"
#include "protocol/ProtocolClient.hpp"

NetworkClient& NetworkClient::get()
{
    static NetworkClient instance;
    return instance;
}

NetworkClient::NetworkClient() : socket(io_context)
{
}

NetworkClient::~NetworkClient()
{
    stop();
}

const void NetworkClient::init(const std::string ip, const unsigned short port)
{
    this->host = ip;
    this->port = port;
}

const void NetworkClient::stop()
{
    running = false;
    io_context.stop();

    if (networkThread.joinable())
    {
        networkThread.join();
    }
}

const void NetworkClient::run()
{
    try
    {
        asio::ip::tcp::resolver resolver(io_context);
        asio::ip::tcp::resolver::results_type endpoints =
            resolver.resolve(host, std::to_string(port));

        asio::connect(socket, endpoints);

        std::cout << "Connected to server: " << host << ":" << port << std::endl;

        networkThread = std::thread(&NetworkClient::receive, this);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Network connection error: " << e.what() << std::endl;
        exit(0);
    }
}

const void NetworkClient::send(SmartBuffer& smartBuffer)
{
    try
    {
        asio::write(socket, asio::buffer(smartBuffer.getBuffer(), smartBuffer.getSize()));
    }
    catch (const std::exception& e)
    {
        std::cerr << "Send error: " << e.what() << std::endl;
        exit(0);
    }
}

const void NetworkClient::receive()
{
    SmartBuffer smartBuffer;

    try
    {
        while (running)
        {
            asio::error_code error;

            uint32_t packetSize;
            asio::read(socket, asio::buffer(&packetSize, sizeof(packetSize)), error);
            if (error)
            {
                throw asio::system_error(error);
            }

            std::vector<uint8_t> buffer(packetSize);
            asio::read(socket, asio::buffer(buffer.data(), packetSize), error);
            if (error)
            {
                throw asio::system_error(error);
            }

            smartBuffer.reset();
            smartBuffer.inject(buffer.data(), packetSize);

            ProtocolClient::get().handleMessage(smartBuffer);
        }
    }
    catch (const std::exception& e)
    {
        if (running)
        {
            std::cerr << "Receive error: " << e.what() << std::endl;
        }
    }
}

uint32_t NetworkClient::getCutPacketSize(SmartBuffer smartBuffer, const uint32_t size) const
{
    return (smartBuffer.getSize() - sizeof(OpCodes)) / size;
}

uint64_t NetworkClient::getPing() const
{
    return ping;
}

const void NetworkClient::setPing(const uint64_t newPing)
{
    ping = newPing;
}

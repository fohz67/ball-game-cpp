#include "engine/Network.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>

#include "config/Config.hpp"
#include "managers/PlayerManager.hpp"
#include "protocol/Protocol.hpp"
#include "protocol/Send.hpp"

Network& Network::get()
{
    static Network instance;
    return instance;
}

Network::Network()
    : acceptor(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), Config::Network::PORT))
{
}

const void Network::run()
{
    asyncAccept();

    sendThread = std::thread(&Network::sendLoop, this);

    io_context.run();
}

const void Network::asyncAccept()
{
    acceptor.async_accept(
        [this](std::error_code ec, asio::ip::tcp::socket socket)
        {
            if (!ec)
            {
                const auto client = std::make_shared<asio::ip::tcp::socket>(std::move(socket));

                PlayerManager::get().newPlayer(client);

                asyncRead(client);
            }

            asyncAccept();
        });
}

const void Network::asyncRead(const std::shared_ptr<asio::ip::tcp::socket> socket)
{
    auto buffer = std::make_shared<std::vector<char>>(Config::Network::MAX_SIZE);

    socket->async_read_some(asio::buffer(*buffer),
                            [this, socket, buffer](std::error_code ec, std::size_t length)
                            {
                                if (!ec)
                                {
                                    SmartBuffer smartBuffer;

                                    Protocol::get().injector(buffer->data(), length, smartBuffer);
                                    Protocol::get().handleMessage(socket, smartBuffer);

                                    this->asyncRead(socket);
                                }
                                else
                                {
                                    PlayerManager::get().removePlayer(socket);
                                }
                            });
}

const void Network::sendToClient(const std::shared_ptr<asio::ip::tcp::socket>& client,
                                 SmartBuffer& smartBuffer)
{
    if (client && client->is_open())
    {
        const uint32_t packetSize = smartBuffer.getSize();

        std::vector<uint8_t> data(sizeof(uint32_t) + packetSize);

        std::memcpy(data.data(), &packetSize, sizeof(uint32_t));
        std::memcpy(data.data() + sizeof(uint32_t), smartBuffer.getBuffer(), packetSize);

        asio::write(*client, asio::buffer(data));
    }
}

const void Network::sendToAll(SmartBuffer& smartBuffer)
{
    const std::vector<Player*> players = PlayerManager::get().getPlayers();

    for (const Player* player : players)
    {
        sendToClient(player->getClient(), smartBuffer);
    }
}

const void Network::sendLoop()
{
    while (true)
    {
        auto start = std::chrono::steady_clock::now();

        Send::sendCells();
        Send::sendPlayerUpdate();

        auto end = std::chrono::steady_clock::now();
        double duration = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "[Network] Loop iteration took " << std::fixed << std::setprecision(5)
                  << duration << " ms" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(Config::Network::FREQUENCY));
    }
}
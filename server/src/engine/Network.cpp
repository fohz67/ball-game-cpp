#include "engine/Network.hpp"
#include <iostream>
#include "config/Config.hpp"
#include "managers/PlayerManager.hpp"
#include "protocol/Protocol.hpp"

Network& Network::get() {
    static Network instance;
    return instance;
}

Network::Network()
    : acceptor(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(),
                                                   Config::Network::PORT)) {}

void Network::run() {
    doAccept();
    sendThread = std::thread(&Network::sendLoop, this);
    io_context.run();
}

void Network::doAccept() {
    acceptor.async_accept(
        [this](std::error_code ec, asio::ip::tcp::socket socket) {
            if (!ec) {
                auto clientSocket =
                    std::make_shared<asio::ip::tcp::socket>(std::move(socket));

                Player newPlayer = PlayerManager::get().addPlayer(clientSocket);

                std::cout << "New player connected: " << newPlayer.getId()
                          << " from " << clientSocket->remote_endpoint()
                          << std::endl;

                newClient(clientSocket);
            }

            doAccept();
        });
}

void Network::newClient(std::shared_ptr<asio::ip::tcp::socket> socket) {
    auto buffer =
        std::make_shared<std::vector<char>>(Config::Network::MAX_SIZE);

    socket->async_read_some(
        asio::buffer(*buffer),
        [this, socket, buffer](std::error_code ec, std::size_t length) {
            if (!ec) {
                SmartBuffer smartBuffer;

                Protocol::get().injector(buffer->data(), length, smartBuffer);
                Protocol::get().handleMessage(socket, smartBuffer);

                this->newClient(socket);
            } else {
                uint32_t playerId =
                    PlayerManager::get().getPlayerByClient(socket)->getId();

                PlayerManager::get().removePlayer(playerId);

                std::cout << "Player " << playerId << " disconnected."
                          << std::endl;
            }
        });
}

void Network::sendToClient(std::shared_ptr<asio::ip::tcp::socket> client,
                           SmartBuffer& smartBuffer) {
    if (client && client->is_open()) {
        uint32_t packetSize = smartBuffer.getSize();
        std::vector<uint8_t> data(sizeof(uint32_t) + packetSize);

        std::memcpy(data.data(), &packetSize, sizeof(uint32_t));
        std::memcpy(data.data() + sizeof(uint32_t), smartBuffer.getBuffer(),
                    packetSize);

        asio::write(*client, asio::buffer(data));
    }
}

void Network::sendToAll(SmartBuffer& smartBuffer) {
    const auto& players = PlayerManager::get().getAllPlayers();

    for (const auto& player : players) {
        sendToClient(player.getClient(), smartBuffer);
    }
}

void Network::sendLoop() {
    while (true) {
        Protocol::get().sendCells();
        Protocol::get().sendViewport();

        std::this_thread::sleep_for(
            std::chrono::milliseconds(Config::Network::FREQUENCY));
    }
}

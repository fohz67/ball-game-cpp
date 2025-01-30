#include "network/Network.hpp"
#include "config/Config.hpp"
#include "network/Protocol.hpp"
#include "player/PlayerManager.hpp"
#include "cell/CellManager.hpp"

Network& Network::get() {
    static Network instance;
    return instance;
}

Network::Network()
    : acceptor(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(),
                                                   Config::Network::PORT)) {}

void Network::run() {
    doAccept();
    std::thread sendThread(&Network::sendLoop, this);
    io_context.run();
}

void Network::doAccept() {
    acceptor.async_accept([this](std::error_code ec,
                                 asio::ip::tcp::socket socket) {
        if (!ec) {
            auto client_socket =
                std::make_shared<asio::ip::tcp::socket>(std::move(socket));
            Player player = PlayerManager::get().addPlayer(client_socket);
            std::cout << "New player connected: " << player.getId() << " from "
                      << client_socket->remote_endpoint() << std::endl;
            handleClient(client_socket);
        }
        doAccept();
    });
}

void Network::handleClient(std::shared_ptr<asio::ip::tcp::socket> socket) {
    auto buffer = std::make_shared<std::vector<char>>(MAX_BUFFER_SIZE);

    socket->async_read_some(
        asio::buffer(*buffer),
        [this, socket, buffer](std::error_code ec, std::size_t length) {
            if (!ec) {
                SmartBuffer smartBuffer;
                Protocol::get().injector(buffer->data(), length, smartBuffer);
                Protocol::get().handleMessage(socket, smartBuffer);
                this->handleClient(socket);
            } else {
                uint32_t playerId =
                    PlayerManager::get().getPlayerByClient(socket)->getId();
                PlayerManager::get().removePlayer(playerId);
                std::cerr << "Player " << playerId << " disconnected."
                          << std::endl;
            }
        });
}

void Network::sendToClient(std::shared_ptr<asio::ip::tcp::socket> client,
                             SmartBuffer& smartBuffer) {
    if (client && client->is_open()) {
        asio::write(*client, asio::buffer(smartBuffer.getBuffer(),
                                          smartBuffer.getSize()));
    }
}

void Network::sendToAll(SmartBuffer& smartBuffer) {
    const auto& allPlayers = PlayerManager::get().getAllPlayers();
    for (const auto& player : allPlayers) {
        sendToClient(player.getClient(), smartBuffer);
    }
}

void Network::sendLoop() {
    while (true) {
        Protocol::get().sendGameState();
        Protocol::get().sendViewport();
        std::this_thread::sleep_for(std::chrono::milliseconds(Config::Network::FREQUENCY));
    }
}

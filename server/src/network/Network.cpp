#include "network/Network.hpp"
#include "GameConfig.hpp"
#include "network/Protocol.hpp"
#include "players/PlayersManager.hpp"

Network& Network::get() {
    static Network instance;
    return instance;
}

Network::Network()
    : acceptor(io_context,
               asio::ip::tcp::endpoint(asio::ip::tcp::v4(), GameConfig::PORT)),
      port(GameConfig::PORT) {}

void Network::run() {
    do_accept();
    sendThread = std::thread(&Network::send_loop, this);
    io_context.run();
}

void Network::do_accept() {
    acceptor.async_accept([this](std::error_code ec,
                                 asio::ip::tcp::socket socket) {
        if (!ec) {
            auto client_socket =
                std::make_shared<asio::ip::tcp::socket>(std::move(socket));
            Player player = PlayersManager::get().addPlayer(client_socket);
            std::cout << "New player connected: " << player.getId() << " from "
                      << client_socket->remote_endpoint() << std::endl;
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
                Protocol::get().injector(buffer->data(), length, smartBuffer);
                Protocol::get().handle_message(socket, smartBuffer);
                this->handle_client(socket);
            } else {
                uint32_t playerId =
                    PlayersManager::get().getPlayerByClient(socket)->getId();
                PlayersManager::get().removePlayer(playerId);
                std::cerr << "Player " << playerId << " disconnected."
                          << std::endl;
            }
        });
}

void Network::send_to_client(std::shared_ptr<asio::ip::tcp::socket> client,
                             SmartBuffer& smartBuffer) {
    if (client && client->is_open()) {
        asio::write(*client, asio::buffer(smartBuffer.getBuffer(),
                                          smartBuffer.getSize()));
    }
}

void Network::send_to_all(SmartBuffer& smartBuffer) {
    const auto& allPlayers = PlayersManager::get().getAllPlayers();
    for (const auto& player : allPlayers) {
        send_to_client(player.getClient(), smartBuffer);
    }
}

void Network::send_loop() {
    while (true) {
        // Protocol::get().sendGameState();
        // Protocol::get().sendViewport();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

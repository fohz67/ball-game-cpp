#include "Client.hpp"
#include "config/ConfigClient.hpp"
#include "engine/GameClient.hpp"
#include "engine/NetworkClient.hpp"
#include "protocol/ProtocolClient.hpp"

Client& Client::get() {
    static Client instance;
    return instance;
}

void Client::run(const char** av) {
    std::string host = av[1] ? av[1] : ConfigClient::Network::HOST;
    unsigned short port = av[2] ? static_cast<unsigned short>(std::stoi(av[2]))
                                : ConfigClient::Network::PORT;
    std::string nickname = av[3] ? av[3] : "An Unnamed Cell";

    NetworkClient::get().init(host, port);
    NetworkClient::get().run();

    ProtocolClient::get().sendJoin(nickname);

    GameClient::get().run();
}

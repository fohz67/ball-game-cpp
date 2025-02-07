#include "Client.hpp"

#include "config/ConfigClient.hpp"
#include "engine/GameClient.hpp"
#include "engine/NetworkClient.hpp"
#include "protocol/SendClient.hpp"

Client& Client::get()
{
    static Client instance;
    return instance;
}

const void Client::run(const char** av)
{
    const std::string host = av[1] ? av[1] : ConfigClient::Network::HOST;
    const unsigned short port =
        av[2] ? static_cast<unsigned short>(std::stoi(av[2])) : ConfigClient::Network::PORT;
    const std::string nickname = av[3] ? av[3] : "An Unnamed Cell";

    NetworkClient::get().init(host, port);
    NetworkClient::get().run();

    SendClient::sendJoin(nickname);

    GameClient::get().run();
}

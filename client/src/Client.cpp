#include "Client.hpp"
#include <getopt.h>
#include <iostream>
#include "config/ConfigClient.hpp"
#include "engine/GameClient.hpp"
#include "engine/NetworkClient.hpp"
#include "protocol/SendClient.hpp"

Client& Client::get()
{
    static Client instance;
    return instance;
}

const void Client::run(const int ac, const char** av)
{
    std::string host = ConfigClient::Network::HOST;
    unsigned short port = ConfigClient::Network::PORT;
    std::string nickname = "";

    int opt;
    while ((opt = getopt(ac, const_cast<char**>(av), "i:p:n:")) != -1) {
        switch (opt) {
            case 'i':
                host = optarg;
                break;
            case 'p':
                port = static_cast<unsigned short>(std::stoi(optarg));
                break;
            case 'n':
                nickname = optarg;
                break;
            default:
                std::cerr << "Usage: " << av[0] << " [-i ip] [-p port] [-n nickname]" << std::endl;
                exit(1);
        }
    }

    NetworkClient::get().init(host, port);
    NetworkClient::get().run();

    SendClient::sendJoin(nickname);

    GameClient::get().run();
}

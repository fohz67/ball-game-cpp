#pragma once

#include <thread>
#include "CNetwork.hpp"
#include "GameState.hpp"

class Client
{
public:
    Client(const std::string &host, unsigned short port);
    void start();

private:
    void game_loop();
    void run_game_state();

    CNetwork network;
    GameState game_state;
    std::thread game_thread;
    std::thread render_thread;
};

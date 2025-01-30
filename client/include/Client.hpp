#pragma once

#include <thread>
#include "CNetwork.hpp"
#include "GameState.hpp"

class Client {
  public:
    Client(const std::string& host, unsigned short port);
    void run();

  private:
    void join();
    CNetwork network;
    GameState game_state;
    std::thread render_thread;
};

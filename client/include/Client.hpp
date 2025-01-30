#pragma once

#include <thread>
#include "game_components/CWorld.hpp"
#include "game_components/GameState.hpp"
#include "network/CNetwork.hpp"
#include "network/CProtocol.hpp"

class Client {
  public:
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
    static Client& get();
    void run();

  private:
    Client() = default;
    ~Client() = default;
    void join();
    std::thread render_thread;
};

#pragma once

#include <thread>
#include "game/GameState.hpp"
#include "network/NetworkClient.hpp"
#include "network/ProtocolClient.hpp"

class Client {
  public:
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
    static Client& get();
    void run(const char** av);

  private:
    Client() = default;
    ~Client() = default;
    void join();
    std::thread render_thread;
};

#pragma once

#include "network/Network.hpp"
#include "world/World.hpp"

class Server {
  public:
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;
    static Server& get();
    void run();

  private:
    Server() = default;
    ~Server() = default;
    void updateLoop();
    std::thread updateThread;
};

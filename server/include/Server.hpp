#pragma once

#include "comps/world/World.hpp"
#include "network/Network.hpp"

class Server {
  public:
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;
    static Server& get();
    void run();

  private:
    Server() = default;
    ~Server() = default;
};

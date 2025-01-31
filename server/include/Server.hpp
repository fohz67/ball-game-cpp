#pragma once

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

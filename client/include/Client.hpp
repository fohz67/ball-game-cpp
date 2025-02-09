#pragma once

class Client
{
   public:
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;

    static Client& get();

    const void run(const int ac, const char** av);

   private:
    Client() = default;
    ~Client() = default;
};

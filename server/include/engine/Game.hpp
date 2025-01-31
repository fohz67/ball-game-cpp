#pragma once

#include <thread>

class Game {
  public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    static Game& get();

    void run();

  private:
    Game() = default;
    ~Game() = default;

    std::thread updateThread;
};

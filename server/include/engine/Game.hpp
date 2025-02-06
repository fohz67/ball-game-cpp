#pragma once

#include <thread>
#include "components/Player.hpp"

class Game {
  public:
    Game(const Game&)            = delete;
    Game& operator=(const Game&) = delete;

    static Game& get();

    const void run();

    const void updateLoop();
    const void updateGameState(Player* player);

  private:
    Game()  = default;
    ~Game() = default;

    std::thread updateThread;
};

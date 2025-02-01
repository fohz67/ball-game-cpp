#pragma once

#include <thread>
#include "components/Player.hpp"

class Game {
  public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    static Game& get();

    void run();
    void updateLoop();
    void viewportUpdate(Player& player);
    void cellMoveUpdate(Player& player);

  private:
    Game() = default;
    ~Game() = default;

    std::thread updateThread;
};

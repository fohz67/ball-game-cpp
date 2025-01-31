#include "engine/Game.hpp"

Game& Game::get() {
    static Game instance;
    return instance;
}

void Game::run() {
    // @TODO implement game loop
}

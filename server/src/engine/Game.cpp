#include "engine/Game.hpp"
#include <cmath>
#include "components/Cell.hpp"
#include "config/Config.hpp"
#include "geometry/FastInvSqrt.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"

Game& Game::get() {
    static Game instance;
    return instance;
}

const void Game::run() {
    CellManager::get().generatePellets();

    updateThread = std::thread(&Game::updateLoop, this);
}

const void Game::updateLoop() {
    while (true) {
        CellManager::get().updateCells();

        for (Player& player : PlayerManager::get().getPlayers()) {
            updateGameState(player);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(Config::Game::FREQUENCY));
    }
}

const void Game::updateGameState(Player& player) {
    const double             decrease    = Config::Gameplay::Cell::DECREASE_SPEED_THRESHOLD;
    const std::vector<Cell*> playerCells = CellManager::get().getCells(player.getId());

    if (playerCells.empty()) {
        return;
    }

    Vector2      center(0.0f, 0.0f);
    Vector2      dir       = player.getMousePosition();
    const double magnitude = dir.magnitude();
    const double slowdown  = (magnitude < decrease) ? magnitude / decrease : 1.0f;

    if (magnitude) {
        dir /= magnitude;
    }

    for (Cell* cell : playerCells) {
        center += cell->getCenter();
        cell->move(dir, Config::Gameplay::Cell::SPEED * slowdown);
    }

    center /= playerCells.size();

    player.setViewport(center);
}

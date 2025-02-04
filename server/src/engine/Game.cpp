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

void Game::run() {
    CellManager::get().generatePellets();
    updateThread = std::thread(&Game::updateLoop, this);
}

void Game::updateLoop() {
    while (true) {
        CellManager::get().updateCells();
        PlayerManager::get().updatePlayers();

        std::this_thread::sleep_for(std::chrono::milliseconds(Config::Game::FREQUENCY));
    }
}

void Game::viewportUpdate(Player& player) {
    std::vector<Cell*> playerCells = CellManager::get().getCells(player.getId());
    if (playerCells.empty()) {
        return;
    }

    Vector2 cellCenter(0.0f, 0.0f);

    for (const auto* cell : playerCells) {
        cellCenter += cell->getCenter();
    }

    cellCenter /= playerCells.size();

    player.setViewport(cellCenter);
}

void Game::moveUpdate(const Player& player) {
    std::vector<Cell*> playerCells = CellManager::get().getCells(player.getId());
    if (playerCells.empty()) {
        return;
    }

    Vector2 dir            = player.getMousePosition();
    double  magnitude      = dir.magnitude();
    double  slowdownFactor = (magnitude < Config::Gameplay::Cell::DECREASE_SPEED_THRESHOLD)
                                 ? magnitude / Config::Gameplay::Cell::DECREASE_SPEED_THRESHOLD
                                 : 1.0f;

    if (magnitude) {
        dir /= magnitude;
    }

    for (Cell* cell : playerCells) {
        cell->move(dir, Config::Gameplay::Cell::SPEED * slowdownFactor);
    }
}

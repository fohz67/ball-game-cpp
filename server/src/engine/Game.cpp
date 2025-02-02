#include "engine/Game.hpp"
#include <cmath>
#include <iostream>
#include "components/Cell.hpp"
#include "config/Config.hpp"
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
        CellManager::get().cellPhysics();

        for (auto& player : PlayerManager::get().getAllPlayers()) {
            viewportUpdate(player);
            moveUpdate(player);
        }

        std::this_thread::sleep_for(
            std::chrono::milliseconds(Config::Game::FREQUENCY));
    }
}

void Game::viewportUpdate(Player& player) {
    std::vector<Cell*> playerCells =
        CellManager::get().getCellsFromId(player.getId());
    if (playerCells.empty()) {
        return;
    }

    std::pair cellCenter = {0.0f, 0.0f};

    for (const auto* cell : playerCells) {
        Point playerCellCenter = cell->getCenter();

        cellCenter.first += playerCellCenter.first;
        cellCenter.second += playerCellCenter.second;
    }

    cellCenter.first /= playerCells.size();
    cellCenter.second /= playerCells.size();

    player.setViewport(cellCenter);
}

void Game::moveUpdate(Player& player) {
    std::vector<Cell*> playerCells =
        CellManager::get().getCellsFromId(player.getId());
    if (playerCells.empty()) {
        return;
    }

    Point dir = player.getMousePosition();

    double magnitude = sqrt(dir.first * dir.first + dir.second * dir.second);
    double slowdownFactor =
        (magnitude < Config::Gameplay::Cell::DECREASE_SPEED_THRESHOLD)
            ? magnitude / Config::Gameplay::Cell::DECREASE_SPEED_THRESHOLD
            : 1.0;

    if (magnitude > 0) {
        dir.first /= magnitude;
        dir.second /= magnitude;
    }

    for (size_t i = 0; i < playerCells.size(); ++i) {
        playerCells[i]->move(dir,
                             Config::Gameplay::Cell::SPEED * slowdownFactor);
    }
}

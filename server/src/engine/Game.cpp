#include "engine/Game.hpp"
#include <iostream>
#include "components/Cell.hpp"
#include "config/Config.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"
#include "geometry/FastInvSqrt.hpp"

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
        CellManager::get().resolveEat();

        for (auto& player : PlayerManager::get().getAllPlayers()) {
            viewportUpdate(player);
            moveUpdate(player);
        }

        std::this_thread::sleep_for(
            std::chrono::milliseconds(Config::Network::FREQUENCY));
    }
}

void Game::viewportUpdate(Player& player) {
    std::vector<Cell*> playerCells =
        CellManager::get().getCellsFromId(player.getId());
    if (playerCells.empty()) {
        return;
    }

    double centerX = 0.0f;
    double centerY = 0.0f;

    for (const auto* cell : playerCells) {
        centerX += cell->getX() + cell->getRadius();
        centerY += cell->getY() + cell->getRadius();
    }

    centerX /= playerCells.size();
    centerY /= playerCells.size();

    player.setViewport({centerX, centerY});
}

void Game::moveUpdate(Player& player) {
    std::vector<Cell*> playerCells =
        CellManager::get().getCellsFromId(player.getId());
    if (playerCells.empty())
        return;

    std::pair<double, double> mousePosition = player.getMousePosition();
    double dirX = mousePosition.first;
    double dirY = mousePosition.second;

    double magnitude = fastInvSqrt(dirX * dirX + dirY * dirY);
    double slowdownFactor =
        (magnitude < Config::GameMode::DECREASE_SPEED_THRESHOLD)
            ? magnitude / Config::GameMode::DECREASE_SPEED_THRESHOLD
            : 1.0;

    if (magnitude > 0) {
        dirX /= magnitude;
        dirY /= magnitude;
    }

    double speed = Config::GameMode::CELL_SPEED * slowdownFactor;
    size_t cellCount = playerCells.size();

    for (size_t i = 0; i < cellCount; ++i) {
        playerCells[i]->move(dirX, dirY, speed, Config::GameMode::WORLD_SIZE);
    }
}

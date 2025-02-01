#include "engine/Game.hpp"
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
    updateThread = std::thread(&Game::updateLoop, this);
}

void Game::updateLoop() {
    while (true) {
        for (auto& player : PlayerManager::get().getAllPlayers()) {
            viewportUpdate(player);
            cellMoveUpdate(player);
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

    if (Config::Server::DEV_MODE)
        std::cout << "Viewport updated for player " << player.getId()
                  << "X: " << centerX << " Y: " << centerY << std::endl;
}

void Game::cellMoveUpdate(Player& player) {
    std::vector<Cell*> playerCells =
        CellManager::get().getCellsFromId(player.getId());
    if (playerCells.empty())
        return;

    std::pair<double, double> mousePosition = player.getMousePosition();
    double dirX = mousePosition.first;
    double dirY = mousePosition.second;

    double magnitude = std::sqrt(dirX * dirX + dirY * dirY);
    double slowdownFactor =
        (magnitude < Config::GameMode::MIN_INPUT_THRESHOLD)
            ? magnitude / Config::GameMode::MIN_INPUT_THRESHOLD
            : 1.0;

    if (magnitude > 0) {
        dirX /= magnitude;
        dirY /= magnitude;
    }

    double speed = Config::GameMode::BASE_SPEED * slowdownFactor;
    size_t cellCount = playerCells.size();

    for (size_t i = 0; i < cellCount; ++i) {
        playerCells[i]->move(dirX, dirY, speed, Config::GameMode::WORLD_SIZE);

        for (size_t j = i + 1; j < cellCount; ++j) {
            playerCells[i]->resolveCollision(*playerCells[j]);
        }
    }

    if (Config::Server::DEV_MODE) {
        std::cout << "Cell movement updated for player " << player.getId()
                  << std::endl;
    }
}

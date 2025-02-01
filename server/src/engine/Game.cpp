#include "engine/Game.hpp"
#include "components/Cell.hpp"
#include "components/MousePosition.hpp"
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
        for (const auto& player : PlayerManager::get().getAllPlayers()) {
            viewportUpdate(player);
            cellMoveUpdate(player);
        }

        std::this_thread::sleep_for(
            std::chrono::milliseconds(Config::Network::FREQUENCY));
    }
}

void Game::viewportUpdate(const Player player) {
    std::vector<Cell*> playerCells =
        CellManager::get().getCellsFromId(player.getId());
    if (playerCells.empty()) {
        return;
    }

    double centerX = 0.0f;
    double centerY = 0.0f;

    for (const auto* cell : playerCells) {
        centerX += cell->getX();
        centerY += cell->getY();
    }

    centerX /= playerCells.size();
    centerY /= playerCells.size();

    player.getViewport().updatePosition(centerX, centerY);
}

void Game::cellMoveUpdate(const Player player) {
    std::vector<Cell*> playerCells =
        CellManager::get().getCellsFromId(player.getId());
    if (playerCells.empty()) {
        return;
    }

    MousePosition mousePosition = player.getMousePosition();

    double dirX = mousePosition.x;
    double dirY = mousePosition.y;

    if (std::fabs(dirX) < 0.05f) {
        dirX = 0;
    }
    if (std::fabs(dirY) < 0.05f) {
        dirY = 0;
    }

    for (auto* cell : playerCells) {
        double radius = cell->getRadius();
        double speed = 100.0f / std::log(radius + 1.5f);

        double newX = cell->getX() + dirX * speed;
        double newY = cell->getY() + dirY * speed;

        for (auto* otherCell : playerCells) {
            if (cell == otherCell) {
                continue;
            }

            double dx = newX - otherCell->getX();
            double dy = newY - otherCell->getY();

            double distance = std::sqrt(dx * dx + dy * dy);
            double minDist = radius + otherCell->getRadius();

            if (distance < minDist) {
                double overlap = minDist - distance;

                newX += dx / distance * overlap * 0.5f;
                newY += dy / distance * overlap * 0.5f;
            }
        }

        cell->setPosition(newX, newY);
    }
}

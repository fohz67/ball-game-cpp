#include "engine/Game.hpp"

#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>

#include "components/Cell.hpp"
#include "config/Config.hpp"
#include "engine/AI.hpp"
#include "geometry/FastInvSqrt.hpp"
#include "managers/CellManager.hpp"
#include "managers/LeaderboardManager.hpp"
#include "managers/PlayerManager.hpp"

Game& Game::get()
{
    static Game instance;
    return instance;
}

const void Game::run()
{
    PlayerManager::get().generateBots();
    CellManager::get().generatePellets();

    updateThread = std::thread(&Game::updateLoop, this);
}

const void Game::updateLoop()
{
    while (true)
    {
        auto start = std::chrono::steady_clock::now();

        CellManager::get().updateCells();
        LeaderboardManager::get().updateLeaderboard();
        updateGameState();

        if (Config::Game::DEBUG)
        {
            auto end = std::chrono::steady_clock::now();
            double duration = std::chrono::duration<double, std::milli>(end - start).count();
            std::cout << "[Game] Loop iteration took " << std::fixed << std::setprecision(5)
                      << duration << " ms" << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(Config::Game::FREQUENCY));
    }
}

const void Game::updateGameState()
{
    const std::vector<Player*> players = PlayerManager::get().getPlayers();

    for (Player* player : players)
    {
        const std::vector<Cell*> playerCells =
            CellManager::get().getCellsByPlayerId(player->getId());

        if (playerCells.empty())
        {
            return;
        }

        Vector2 center(0.0f, 0.0f);
        Vector2 dir;

        if (player->getIsBot())
        {
            dir = AI::computeAIMovement(player->getId());
        }
        else
        {
            dir = player->getMousePosition();
        }

        const double magnitude = dir.magnitude();
        const double decrease = Config::Gameplay::Cell::DECREASE_SPEED_THRESHOLD;
        const double slowdown = (magnitude < decrease) ? magnitude / decrease : 1.0f;

        if (magnitude)
        {
            dir /= magnitude;
        }

        for (Cell* cell : playerCells)
        {
            center += cell->getCenter();
            cell->move(dir, Config::Gameplay::Cell::SPEED * slowdown);
        }

        center /= playerCells.size();

        player->setViewport(center);
    }
}

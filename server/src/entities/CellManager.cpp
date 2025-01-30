#include "cell/CellManager.hpp"
#include <random>
#include <iostream>
#include <cmath>
#include "config/Config.hpp"

CellManager& CellManager::get() {
    static CellManager instance;
    return instance;
}

void CellManager::createCell(uint32_t playerId) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> disX(0, Config::World::WIDTH);
    std::uniform_real_distribution<float> disY(0, Config::World::HEIGHT);
    float spawnX = disX(gen);
    float spawnY = disY(gen);
    CellManager::get().addCell(playerId, spawnX, spawnY,
                               Config::Cell::DEFAULT_RADIUS,
                               Config::Cell::DEFAULT_SPEED);
}

void CellManager::addCell(uint32_t ownerId, float x, float y, float radius,
                          float speed) {
    cells.emplace_back(ownerId, x, y, radius, speed);
}

void CellManager::removePlayerCells(uint32_t ownerId) {
    cells.erase(std::remove_if(cells.begin(), cells.end(),
                               [ownerId](const Cell& cell) {
                                   return cell.getOwnerId() == ownerId;
                               }),
                cells.end());
}

const std::vector<Cell>& CellManager::getCells() const {
    return cells;
}

std::vector<Cell*> CellManager::getPlayerCells(uint32_t playerId)  {
    std::vector<Cell*> playerCells;
    for (auto& cell : cells) {
        if (cell.getOwnerId() == playerId) {
            playerCells.push_back(&cell);
        }
    }
    return playerCells;
}

void CellManager::updateCellMovement(uint32_t playerId, float normMouseX, float normMouseY) {
    std::vector<Cell*> playerCells = getPlayerCells(playerId);
    if (playerCells.empty()) return;

    float centerX = 0.0f, centerY = 0.0f;
    for (const auto* cell : playerCells) {
        centerX += cell->getX();
        centerY += cell->getY();
    }
    centerX /= playerCells.size();
    centerY /= playerCells.size();

    float dirX = normMouseX;
    float dirY = normMouseY;

    if (std::fabs(dirX) < 0.05f) dirX = 0;
    if (std::fabs(dirY) < 0.05f) dirY = 0;

    for (auto* cell : playerCells) {
        float radius = cell->getRadius();
        float speed = 100.0f / std::log(radius + 1.5f);

        float newX = cell->getX() + dirX * speed;
        float newY = cell->getY() + dirY * speed;

        for (auto* otherCell : playerCells) {
            if (cell == otherCell) continue;

            float dx = newX - otherCell->getX();
            float dy = newY - otherCell->getY();
            float distance = std::sqrt(dx * dx + dy * dy);
            float minDist = radius + otherCell->getRadius();

            if (distance < minDist) {
                float overlap = minDist - distance;
                newX += dx / distance * overlap * 0.5f;
                newY += dy / distance * overlap * 0.5f;
            }
        }

        cell->setPosition(newX, newY);
    }
}

#include "cell/CellManager.hpp"
#include <cmath>
#include <iostream>
#include <random>
#include "config/Config.hpp"

CellManager& CellManager::get() {
    static CellManager instance;
    return instance;
}

CellManager::CellManager()
    : quadtree(0, 0, Config::World::WIDTH, Config::World::HEIGHT) {}

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
    cells.emplace_back(ownerId, x, y, radius);
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

std::vector<Cell*> CellManager::getPlayerCells(uint32_t playerId) {
    std::vector<Cell*> playerCells;
    for (auto& cell : cells) {
        if (cell.getOwnerId() == playerId) {
            playerCells.push_back(&cell);
        }
    }
    return playerCells;
}

std::pair<float, float> CellManager::calculateViewport(uint32_t playerId) {
    std::vector<Cell*> playerCells = getPlayerCells(playerId);
    if (playerCells.empty()) {
        return {0, 0};
    }

    float totalMass = 0.0f;
    float centerX = 0.0f, centerY = 0.0f;

    for (const auto* cell : playerCells) {
        float mass = cell->getMass();
        Vector2 position = cell->getPosition();
        float offsetX = position.x + cell->getRadius();
        float offsetY = position.y + cell->getRadius();
        
        centerX += offsetX * mass;
        centerY += offsetY * mass;
        totalMass += mass;
    }

    if (totalMass > 0) {
        centerX /= totalMass;
        centerY /= totalMass;
    }

    return {centerX, centerY};
}

std::vector<Cell*> CellManager::getNearbyCells(Cell* cell) {
    return quadtree.retrieve(cell);
}

void CellManager::update() {
    quadtree.clear();
    for (auto& cell : cells) {
        quadtree.insert(&cell);
    }
}

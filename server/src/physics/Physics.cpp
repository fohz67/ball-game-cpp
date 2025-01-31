#include "physics/Physics.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include "cell/CellManager.hpp"
#include "config/Config.hpp"

void Physics::updateCellMovement(std::vector<Cell*>& cells, float normMouseX,
                                 float normMouseY) {
    if (cells.empty())
        return;

    float centerX = 0.0f, centerY = 0.0f;
    for (const auto* cell : cells) {
        centerX += cell->getPosition().x;
        centerY += cell->getPosition().y;
    }
    centerX /= cells.size();
    centerY /= cells.size();

    float dirX = normMouseX;
    float dirY = normMouseY;
    float distance = std::sqrt(dirX * dirX + dirY * dirY);

    float minThreshold = 0.05f;
    float maxThreshold = 0.5f;
    float slowFactor = std::clamp(
        (distance - minThreshold) / (maxThreshold - minThreshold), 0.0f, 1.0f);

    if (distance < minThreshold) {
        dirX = 0;
        dirY = 0;
        slowFactor = 0;
    }

    for (auto* cell : cells) {
        float radius = cell->getRadius();
        float baseSpeed = Config::GameMode::BASE_SPEED *
                          std::pow(radius, Config::GameMode::SPEED_EXPONENT);
        float adjustedSpeed = baseSpeed * slowFactor;

        float newX = cell->getPosition().x + dirX * adjustedSpeed;
        float newY = cell->getPosition().y + dirY * adjustedSpeed;

        for (auto* otherCell : cells) {
            if (cell == otherCell)
                continue;
            float dx = newX - otherCell->getPosition().x;
            float dy = newY - otherCell->getPosition().y;
            float distance = std::sqrt(dx * dx + dy * dy);
            float minDist = radius + otherCell->getRadius();

            if (distance < minDist) {
                float overlap = minDist - distance;
                newX += dx / distance * overlap * 0.5f;
                newY += dy / distance * overlap * 0.5f;
            }
        }

        cell->setPosition(Vector2(newX, newY));
    }
}

void Physics::applyDecay(std::vector<Cell*>& cells) {
    for (auto* cell : cells) {
        float newMass = cell->getMass() * Config::GameMode::DECAY_SCALE;
        if (newMass < Config::GameMode::MIN_MASS_TO_EJECT) {
            cell->markForDeletion();
        } else {
            cell->setRadius(std::sqrt(newMass / M_PI));
        }
    }
}

void Physics::handleMerging(std::vector<Cell*>& cells) {
    for (size_t i = 0; i < cells.size(); ++i) {
        for (size_t j = i + 1; j < cells.size(); ++j) {
            if (cells[i]->getOwnerId() == cells[j]->getOwnerId()) {
                float mergeTime =
                    Config::GameMode::MERGE_TIME +
                    cells[i]->getMass() * Config::GameMode::MERGE_TIME_SCALE;
                if (cells[i]->getAge() > mergeTime &&
                    cells[j]->getAge() > mergeTime) {
                    cells[i]->setRadius(std::sqrt(
                        (cells[i]->getMass() + cells[j]->getMass()) / M_PI));
                    cells[j]->markForDeletion();
                }
            }
        }
    }
}

void Physics::splitCell(std::vector<Cell*>& cells, uint32_t playerId,
                        float normMouseX, float normMouseY) {
    std::vector<Cell*> newCells;

    for (auto* cell : cells) {
        if (cell->getOwnerId() != playerId)
            continue;

        float mass = cell->getMass();
        if (mass < Config::GameMode::MIN_MASS_TO_SPLIT)
            continue;

        float newMass = mass / 2.0f;
        float newRadius = std::sqrt(newMass / M_PI);

        float dirX = normMouseX;
        float dirY = normMouseY;
        float magnitude = std::sqrt(dirX * dirX + dirY * dirY);
        if (magnitude > 0) {
            dirX /= magnitude;
            dirY /= magnitude;
        } else {
            dirX = 1.0f;
            dirY = 0.0f;
        }

        float offsetX = dirX * (cell->getRadius() * 1.5f);
        float offsetY = dirY * (cell->getRadius() * 1.5f);
        float newX = cell->getPosition().x + offsetX;
        float newY = cell->getPosition().y + offsetY;

        CellManager::get().addCell(playerId, newX, newY, newRadius);
        cell->setRadius(newRadius);
    }

    CellManager::get().update();
}

void Physics::resolveRigidCollision(Cell* a, Cell* b) {
    float dx = b->getPosition().x - a->getPosition().x;
    float dy = b->getPosition().y - a->getPosition().y;
    float distance = std::sqrt(dx * dx + dy * dy);
    float minDist = a->getRadius() + b->getRadius();

    if (distance >= minDist)
        return;

    float overlap = minDist - distance;
    float aFactor = b->getMass() / (a->getMass() + b->getMass());
    float bFactor = a->getMass() / (a->getMass() + b->getMass());

    a->setPosition(
        Vector2(a->getPosition().x - dx / distance * overlap * aFactor,
                a->getPosition().y - dy / distance * overlap * aFactor));
    b->setPosition(
        Vector2(b->getPosition().x + dx / distance * overlap * bFactor,
                b->getPosition().y + dy / distance * overlap * bFactor));
}

bool Physics::resolveEat(Cell* predator, Cell* prey) {
    if (prey->getMass() * Config::GameMode::WORLD_EAT_SIZE_REQ >
        predator->getMass())
        return false;

    float dx = prey->getPosition().x - predator->getPosition().x;
    float dy = prey->getPosition().y - predator->getPosition().y;
    float distance = std::sqrt(dx * dx + dy * dy);

    if (distance >
        predator->getRadius() -
            prey->getRadius() * Config::GameMode::WORLD_EAT_OVERLAP_REQ)
        return false;

    predator->setRadius(
        std::sqrt((predator->getMass() + prey->getMass()) / M_PI));
    prey->markForDeletion();
    return true;
}

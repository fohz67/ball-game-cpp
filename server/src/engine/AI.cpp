#include "engine/AI.hpp"

#include <chrono>
#include <cmath>
#include <random>

#include "config/Config.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"

static Vector2 getRandomDirection()
{
    static std::mt19937 rng(std::random_device{}());
    static std::uniform_real_distribution<float> angleDist(0.0f, 2.0f * M_PI);

    float angle = angleDist(rng);
    return Vector2(std::cos(angle), std::sin(angle));
}

static uint64_t getCurrentTimeMillis()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(
               std::chrono::system_clock::now().time_since_epoch())
        .count();
}

static uint64_t lastTargetChange = getCurrentTimeMillis();
static Vector2 lastRandomDirection = getRandomDirection();

Vector2 AI::computeAIMovement(const uint32_t myId)
{
    Vector2 targetPosition(0.0f, 0.0f);
    double bestDistance = Config::Gameplay::Bot::HUNT_RADIUS;
    bool foundTarget = false;
    bool escaping = false;

    const std::vector<Cell*> myCells = CellManager::get().getCellsByPlayerId(myId);
    if (myCells.empty()) return getRandomDirection() * Config::Gameplay::Bot::RANDOM_WANDER_SPEED;

    Vector2 myCenter(0.0f, 0.0f);
    double myMass = 0.0;

    for (Cell* cell : myCells)
    {
        myCenter += cell->getCenter();
        myMass += cell->getMass();
    }
    myCenter /= myCells.size();

    Vector2 escapeDirection(0.0f, 0.0f);
    double escapeThreatLevel = 0.0;
    bool shouldAbandonTarget = false;

    for (Player* player : PlayerManager::get().getPlayers())
    {
        if (player->getId() == myId) continue;

        std::vector<Cell*> targetCells = CellManager::get().getCellsByPlayerId(player->getId());
        if (targetCells.empty()) continue;

        Vector2 targetCenter(0.0f, 0.0f);
        double targetMass = 0.0;

        for (Cell* cell : targetCells)
        {
            targetCenter += cell->getCenter();
            targetMass += cell->getMass();
        }
        targetCenter /= targetCells.size();

        double distance = (targetCenter - myCenter).magnitude();

        if (targetMass < myMass * Config::Gameplay::Bot::MASS_ADVANTAGE_TO_ATTACK)
        {
            if (distance < bestDistance)
            {
                bestDistance = distance;
                targetPosition = targetCenter;
                foundTarget = true;

                if (distance > Config::Gameplay::Bot::CHASE_ABORT_DISTANCE)
                {
                    shouldAbandonTarget = true;
                }
            }
        }
        else if (targetMass > myMass * Config::Gameplay::Bot::MASS_DISADVANTAGE_TO_FLEE)
        {
            if (distance < Config::Gameplay::Bot::ESCAPE_RADIUS)
            {
                Vector2 threatDirection = myCenter - targetCenter;
                threatDirection.normalize();
                escapeDirection += threatDirection * (1.0 / distance);
                escapeThreatLevel += 1.0 / distance;
                escaping = true;
            }
        }
    }

    if (escaping)
    {
        escapeDirection.normalize();
        return escapeDirection * (Config::Gameplay::Bot::DEFENSE_INTENSITY * 0.02f);
    }

    if (!foundTarget || shouldAbandonTarget)
    {
        for (Cell* pellet : CellManager::get().getPelletCells())
        {
            double distance = (pellet->getCenter() - myCenter).magnitude();
            if (distance < bestDistance)
            {
                bestDistance = distance;
                targetPosition = pellet->getCenter();
                foundTarget = true;
            }
        }
    }

    uint64_t currentTime = getCurrentTimeMillis();
    if (!foundTarget || bestDistance > Config::Gameplay::Bot::CHASE_ABORT_DISTANCE)
    {
        if (currentTime - lastTargetChange > Config::Gameplay::Bot::ABANDON_TARGET_TIME)
        {
            lastRandomDirection = getRandomDirection();
            lastTargetChange = currentTime;
        }

        Vector2 movement = lastRandomDirection * Config::Gameplay::Bot::RANDOM_WANDER_SPEED;

        Vector2 worldSize(Config::Gameplay::World::SIZE, Config::Gameplay::World::SIZE);
        if (myCenter.x < Config::Gameplay::Bot::WORLD_PADDING) movement.x = std::abs(movement.x);
        if (myCenter.y < Config::Gameplay::Bot::WORLD_PADDING) movement.y = std::abs(movement.y);
        if (myCenter.x > worldSize.x - Config::Gameplay::Bot::WORLD_PADDING)
            movement.x = -std::abs(movement.x);
        if (myCenter.y > worldSize.y - Config::Gameplay::Bot::WORLD_PADDING)
            movement.y = -std::abs(movement.y);

        return movement;
    }

    Vector2 movement = targetPosition - myCenter;
    movement.normalize();
    return movement * (Config::Gameplay::Bot::ATTACK_INTENSITY * 0.02f);
}

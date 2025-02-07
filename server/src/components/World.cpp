#include "components/World.hpp"

#include "config/Config.hpp"

std::vector<double> World::getWorldBoundaries()
{
    return {0, Config::Gameplay::World::SIZE, 0, Config::Gameplay::World::SIZE};
}

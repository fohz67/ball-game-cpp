#include "util/Util.hpp"
#include <random>
#include "config/Config.hpp"

Vector2 Util::getRandomLocation() {
    std::random_device                     rd;
    std::mt19937                           gen(rd());
    std::uniform_real_distribution<double> dis(0, Config::Gameplay::World::SIZE);

    return Vector2(dis(gen), dis(gen));
}

std::vector<double> Util::getRandomColor() {
    std::random_device                    rd;
    std::mt19937                          gen(rd());
    std::uniform_real_distribution<float> dis(0, 255);

    return {dis(gen), dis(gen), dis(gen), 255};
}

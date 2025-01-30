#include "comps/world/World.hpp"
#include "util/GameConfig.hpp"

World& World::get() {
    static World instance;
    return instance;
}

World::World()
    : width(GameConfig::WORLD_WIDTH), height(GameConfig::WORLD_WIDTH) {}

int World::get_width() const {
    return width;
}

int World::get_height() const {
    return height;
}

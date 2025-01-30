#include "comps/world/World.hpp"
#include "Config.hpp"

World& World::get() {
    static World instance;
    return instance;
}

World::World() : width(Config::World::WIDTH), height(Config::World::HEIGHT) {}

int World::get_width() const {
    return width;
}

int World::get_height() const {
    return height;
}

#include "World.hpp"

World::World(int width, int height) : width(width), height(height) {}

int World::get_width() const
{
    return width;
}

int World::get_height() const
{
    return height;
}

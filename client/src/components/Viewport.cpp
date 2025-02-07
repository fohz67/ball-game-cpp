#include "components/Viewport.hpp"

#include "config/ConfigClient.hpp"

Viewport& Viewport::get()
{
    static Viewport instance;
    return instance;
}

const void Viewport::setViewport(const Point newViewport)
{
    viewport = newViewport;
}

Point Viewport::getViewport() const
{
    return viewport;
}

Point Viewport::getPreviousViewport() const
{
    return previousViewport;
}

const void Viewport::applyInterpolation()
{
    previousViewport.first +=
        (viewport.first - previousViewport.first) * ConfigClient::Game::CAMERA_INTERPOLATE_FACTOR;
    previousViewport.second +=
        (viewport.second - previousViewport.second) * ConfigClient::Game::CAMERA_INTERPOLATE_FACTOR;
}

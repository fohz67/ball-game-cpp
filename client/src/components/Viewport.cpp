#include "components/Viewport.hpp"
#include "config/ConfigClient.hpp"

Viewport& Viewport::get() {
    static Viewport instance;
    return instance;
}

void Viewport::setViewport(double x, double y) {
    viewport = {x, y};
}

void Viewport::setPreviousViewport(double x, double y) {
    previousViewport = {x, y};
}

std::pair<double, double> Viewport::getViewport() const {
    return viewport;
}

std::pair<double, double> Viewport::getPreviousViewport() const {
    return previousViewport;
}

void Viewport::applyInterpolation() {
    previousViewport.first += (viewport.first - previousViewport.first) *
                              ConfigClient::Game::CAMERA_INTERPOLATE_FACTOR;
    previousViewport.second += (viewport.second - previousViewport.second) *
                               ConfigClient::Game::CAMERA_INTERPOLATE_FACTOR;
}

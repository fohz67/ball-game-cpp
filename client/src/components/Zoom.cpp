#include "components/Zoom.hpp"

#include "config/ConfigClient.hpp"

Zoom& Zoom::get()
{
    static Zoom instance;
    return instance;
}

const void Zoom::setZoom(const double delta, sf::View& view)
{
    if (delta > 0)
    {
        view.zoom(1.0f - ConfigClient::Zoom::SPEED / 1000);
    }
    else if (delta < 0)
    {
        view.zoom(1.0f + ConfigClient::Zoom::SPEED / 1000);
    }
}

#pragma once

#include <SFML/Graphics.hpp>

class Zoom {
  public:
    Zoom(const Zoom&)            = delete;
    Zoom& operator=(const Zoom&) = delete;

    static Zoom& get();

    void setZoom(double delta, sf::View& view);

  private:
    Zoom()  = default;
    ~Zoom() = default;

    double currentZoom;
};

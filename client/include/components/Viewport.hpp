#pragma once

#include <utility>
#include "components/Point.hpp"

class Viewport {
  public:
    Viewport(const Viewport&)            = delete;
    Viewport& operator=(const Viewport&) = delete;

    static Viewport& get();

    void setViewport(Point newViewport);

    Point getViewport() const;
    Point getPreviousViewport() const;

    void applyInterpolation();

  private:
    Viewport()  = default;
    ~Viewport() = default;

    Point viewport{0.0f, 0.0f};
    Point previousViewport{0.0f, 0.0f};
};

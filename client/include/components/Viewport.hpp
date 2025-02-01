#pragma once

#include <utility>

class Viewport {
  public:
    Viewport(const Viewport&) = delete;
    Viewport& operator=(const Viewport&) = delete;

    static Viewport& get();

    void setViewport(double x, double y);
    void setPreviousViewport(double x, double y);

    std::pair<double, double> getViewport() const;
    std::pair<double, double> getPreviousViewport() const;

    void applyInterpolation();

  private:
    Viewport() = default;
    ~Viewport() = default;

    std::pair<double, double> viewport;
    std::pair<double, double> previousViewport;
};

#pragma once

#include <functional>
#include <utility>
#include "components/Components.hpp"
#include "components/Point.hpp"

class Slider : public Component {
  public:
    // Constants
    Slider(const double current, const Point lenght, const Point size);
    ~Slider() = default;

    // Getters
    Point               getSize() const;
    sf::RectangleShape& getBarShape();
    sf::CircleShape&    getCursorShape();
    int                 getValue() const;
    double              getMinValue() const;
    double              getMaxValue() const;
    bool                isLoaded() const;

    // Setters
    void setSize(const Point val);
    void setBarShape(const sf::RectangleShape& val);
    void setCursorShape(const sf::CircleShape& val);
    void setValue(const double var);
    void setMinValue(const double minValue);
    void setMaxValue(const double maxValue);
    void setLoaded();
    void setCallback(const std::function<void(double)> val);

    // Methods
    void executeCallback(const int arg);
    void display() const override;

  private:
    // Constants
    static constexpr bool DEFAULT_LOADED = false;

    // Attributes
    sf::RectangleShape          barShape;
    sf::CircleShape             cursorShape;
    Point                       size;
    double                      min;
    double                      max;
    double                      current;
    bool                        loaded = DEFAULT_LOADED;
    std::function<void(double)> callback;
};

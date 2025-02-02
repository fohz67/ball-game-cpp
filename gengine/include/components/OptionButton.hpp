#pragma once

#include <functional>
#include <utility>
#include "components/Components.hpp"
#include "components/Point.hpp"

class OptionButton : public Component {
  public:
    // Constants
    static inline Point DEFAULT_SIZE = {0.0, 0.0};

    // Constructor / Destructor
    OptionButton(Point size = DEFAULT_SIZE);
    ~OptionButton() = default;

    // Getters
    Point getSize() const;
    sf::RectangleShape& getShape();
    bool isLoaded() const;
    bool isChecked() const;

    // Setters
    void setSize(const Point size);
    void setShape(const sf::RectangleShape&);
    void setLoaded();
    void setChecked();
    void setCallback(const std::function<void()> callbackFunc);

    // Methods
    void executeCallback() const;
    void display() const override;

  private:
    // Constants
    static constexpr bool DEFAULT_LOADED = false;

    // Attributes
    sf::RectangleShape optionbutton;
    Point size;
    std::function<void()> callback;
    bool loaded = DEFAULT_LOADED;
    bool checked = DEFAULT_LOADED;
};

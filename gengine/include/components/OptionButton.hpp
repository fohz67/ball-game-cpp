#pragma once

#include <functional>
#include <utility>
#include "Components.hpp"

class OptionButton : public Component {
  public:
    // Constants
    static inline std::pair<double, double> DEFAULT_SIZE = {0.0, 0.0};

    // Constructor / Destructor
    OptionButton(std::pair<double, double> size = DEFAULT_SIZE);
    ~OptionButton() = default;

    // Getters
    std::pair<double, double> getSize() const;
    sf::RectangleShape& getShape();
    bool isLoaded() const;
    bool isChecked() const;

    // Setters
    void setSize(const std::pair<double, double> size);
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
    std::pair<double, double> size;
    std::function<void()> callback;
    bool loaded = DEFAULT_LOADED;
    bool checked = DEFAULT_LOADED;
};

#pragma once

#include "Components.hpp"
#include <vector>

class Color : public Component {
  public:
    // Constants
    static inline std::vector<double> DEFAULT_COLOR = {0, 0, 0};

    // Constructor / Destructor
    Color(const std::vector<double>& color = DEFAULT_COLOR);
    ~Color() = default;

    // Getters
    std::vector<double> getColor() const;

    // Setters
    void setColor(const std::vector<double>& val);

    // Methods
    void display() const override;

  private:
    // Attributes
    std::vector<double> _initColor;
};

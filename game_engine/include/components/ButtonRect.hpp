#pragma once

#include <SFML/Graphics.hpp>
#include "Components.hpp"
#include <cstdint>
#include <functional>
#include <utility>

class ButtonRect : public Component {
  public:
    // Constants
    static inline std::pair<uint16_t, uint16_t> DEFAULT_SIZE = {150, 50};
    static inline sf::Color DEFAULT_COLOR = sf::Color::Red;
    static constexpr bool DEFAULT_SHOW_OUTLINE = false;

    // Constructor / Destructor
    ButtonRect(const std::pair<uint16_t, uint16_t>& sizeRect = DEFAULT_SIZE,
               const sf::Color color = DEFAULT_COLOR,
               const bool showOutline = DEFAULT_SHOW_OUTLINE);
    ~ButtonRect() = default;

    // Getters
    sf::RectangleShape& getButtonRect();
    std::pair<uint16_t, uint16_t> getSize() const;
    sf::Color getColor() const;
    bool isLoaded() const;
    bool isShowOutline() const;
    bool isHovered(const sf::Vector2i mousePos) const;

    // Setters
    void setLoaded(const bool isLoaded);
    void setCallback(const std::function<void()>& callback);

    // Methods
    void display() const override;
    void executeCallback() const;

  private:
    // Attributes
    sf::RectangleShape buttonRect;
    std::pair<uint16_t, uint16_t> size;
    sf::Color color;
    bool showOutline;
    bool load = false;
    std::function<void()> callback;
};

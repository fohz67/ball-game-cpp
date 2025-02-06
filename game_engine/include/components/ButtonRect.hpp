#pragma once

#include <functional>
#include <utility>
#include "components/Components.hpp"

class ButtonRect : public Component {
  public:
    // Constants
    static inline std::pair<uint16_t, uint16_t> DEFAULT_SIZE         = {150, 50};
    static inline sf::Color                     DEFAULT_COLOR        = sf::Color::Red;
    static constexpr bool                       DEFAULT_SHOW_OUTLINE = false;

    // Constructor / Destructor
    ButtonRect(const std::pair<uint16_t, uint16_t>& sizeRect    = DEFAULT_SIZE,
               const sf::Color                      color       = DEFAULT_COLOR,
               const bool                           showOutline = DEFAULT_SHOW_OUTLINE);
    ~ButtonRect() = default;

    // Getters
    sf::RectangleShape&           getButtonRect();
    std::pair<uint16_t, uint16_t> getSize() const;
    sf::Color                     getColor() const;
    bool                          isLoaded() const;
    bool                          isShowOutline() const;

    // Setters
    void setLoaded(const bool val);
    void setCallback(const std::function<void()>& val);

    // Methods
    bool isHovered(const sf::Vector2i mousePos) const;
    void display() const override;
    void executeCallback() const;

  private:
    // Constants
    static constexpr bool DEFAULT_LOADED = false;

    // Attributes
    sf::RectangleShape            buttonRect;
    std::pair<uint16_t, uint16_t> size;
    sf::Color                     color;
    std::function<void()>         callback;
    bool                          showOutline;
    bool                          load = DEFAULT_LOADED;
};

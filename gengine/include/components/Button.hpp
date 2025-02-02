#pragma once

#include <cstdint>
#include <functional>
#include "Components.hpp"
#include <utility>

class Button : public Component {
  public:
    // Constants
    static inline std::string DEFAULT_TEXT = "";
    static inline std::string FONT_FILE = "";
    static constexpr uint16_t DEFAULT_CHARACTER_SIZE = 30;

    // Constructor / Destructor
    Button(const std::string text = DEFAULT_TEXT,
           const std::string fontFile = FONT_FILE,
           const uint16_t characterSize = DEFAULT_CHARACTER_SIZE);
    ~Button() = default;

    // Getters
    sf::RectangleShape& getButton();
    sf::Text& getText();
    std::string getString() const;
    std::string getFontFile() const;
    uint16_t getCharacterSize() const;
    std::pair<double, double> getSize() const;
    sf::Font& getFont();
    bool isLoaded() const;

    // Setters
    void setString(const std::string val);
    void setLoaded(const bool val);
    void setCallback(const std::function<void()> val);

    // Methods
    bool isHovered(const sf::Vector2i mousePos) const;
    void display() const override;
    void executeCallback() const;

  private:
    // Constants
    static constexpr bool DEFAULT_LOADED = false;

    // Attributes
    sf::RectangleShape button;
    sf::Text text;
    std::string initText;
    std::string fontFile;
    uint16_t characterSize;
    std::pair<double, double> size;
    sf::Font font;
    bool load = DEFAULT_LOADED;
    std::function<void()> callback;
};

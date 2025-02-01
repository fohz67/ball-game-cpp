#pragma once

#include <SFML/Graphics.hpp>
#include "Components.hpp"
#include <cstdint>

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
    sf::Font& getFont();
    uint16_t getCharacterSize() const;
    std::pair<double, double> getSize() const;
    bool isLoaded() const;
    bool isHovered(const sf::Vector2i mousePos) const;

    // Setters
    void setString(const std::string text);
    void setLoaded(bool isLoaded);
    void setCallback(const std::function<void()> callback);

    // Methods
    void display() const override;
    void executeCallback() const;

  private:
    // Attributes
    sf::RectangleShape button;
    sf::Text text;
    std::string initText;
    std::string fontFile;
    uint16_t characterSize;
    std::pair<double, double> size;
    sf::Font font;
    bool load = false;
    std::function<void()> callback;
};

#pragma once

#include <cstdint>
#include <string>
#include <utility>
#include "Components.hpp"

class Text : public Component {
  public:
    // Constants
    static inline std::string DEFAULT_TEXT = "";
    static inline std::string DEFAULT_FONT_FILE = "";
    static constexpr uint16_t DEFAULT_CHARACTER_SIZE = 30;

    // Constructor / Destructor
    Text(const std::string& text = DEFAULT_TEXT,
         const std::string& fontFile = DEFAULT_FONT_FILE,
         uint16_t characterSize = DEFAULT_CHARACTER_SIZE);
    ~Text() = default;

    // Getters
    std::string getString() const;
    sf::Font& getFont();
    uint16_t getCharacterSize() const;
    uint16_t getInitCharacterSize() const;
    bool isLoaded() const;
    std::string getFontFile() const;
    sf::Text& getText();

    // Setters
    void setLoaded(const bool val);
    void setString(const std::string& val);
    void setCharacterSize(const uint16_t val);
    void setFontFile(const std::string val);

    // Methods
    void display() const override;

  private:
    // Constants
    static constexpr bool DEFAULT_LOADED = false;

    // Attributes
    std::string initText;
    uint16_t initSize;
    std::string fontFile;
    uint16_t charSize;
    sf::Text text;
    sf::Font font;
    bool loaded = DEFAULT_LOADED;
};

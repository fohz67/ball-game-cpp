#pragma once

#include <cstdint>
#include <string>
#include <utility>

#include "components/Components.hpp"

class Text : public Component
{
   public:
    // Constants
    static inline std::string DEFAULT_TEXT = "";
    static inline std::string DEFAULT_FONT_FILE = "";
    static constexpr double DEFAULT_CHARACTER_SIZE = 30;
    static constexpr int DEFAULT_CENTERING = 0;

    // Constructor / Destructor
    Text(const std::string& text = DEFAULT_TEXT,
         const std::string& fontFile = DEFAULT_FONT_FILE,
         double characterSize = DEFAULT_CHARACTER_SIZE,
         int centering = DEFAULT_CENTERING);
    ~Text() = default;

    // Getters
    std::string getString() const;
    sf::Font& getFont();
    double getCharacterSize() const;
    double getInitCharacterSize() const;
    bool isLoaded() const;
    std::string getFontFile() const;
    sf::Text& getText();
    int getCentering() const;

    // Setters
    void setLoaded(const bool val);
    void setString(const std::string& val);
    void setCharacterSize(const double val);
    void setFontFile(const std::string val);

    // Methods
    void display() const override;

   private:
    // Constants
    static constexpr bool DEFAULT_LOADED = false;

    // Attributes
    std::string initText;
    double initSize;
    std::string fontFile;
    double charSize;
    sf::Text text;
    sf::Font font;
    int centering = false;
    bool loaded = DEFAULT_LOADED;
};

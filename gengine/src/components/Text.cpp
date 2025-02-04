#include "components/Text.hpp"
#include <iostream>

Text::Text(const std::string& text,
           const std::string& fontFile,
           const double       characterSize,
           const int          centering)
    : initText(text),
      fontFile(fontFile),
      charSize(characterSize),
      initSize(characterSize),
      centering(centering) {}

std::string Text::getString() const {
    return this->initText;
}

sf::Font& Text::getFont() {
    return this->font;
}

double Text::getCharacterSize() const {
    return this->charSize;
}

double Text::getInitCharacterSize() const {
    return this->initSize;
}

bool Text::isLoaded() const {
    return this->loaded;
}

std::string Text::getFontFile() const {
    return this->fontFile;
}

sf::Text& Text::getText() {
    return this->text;
}

int Text::getCentering() const {
    return this->centering;
}

void Text::setString(const std::string& val) {
    this->initText = val;
}

void Text::setCharacterSize(const double val) {
    this->charSize = val;
}

void Text::setFontFile(const std::string val) {
    this->fontFile = val;
}

void Text::setLoaded(const bool val) {
    this->loaded = val;
}

void Text::display() const {
    std::cout << "Text component displayed!" << std::endl;
}

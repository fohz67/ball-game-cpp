/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Text.cpp
**
** The Text class represents a text object with a string attribute.
** It holds the text content in a `std::string` and provides methods to get and
** set the text.
** The constructor allows initializing the text, with a default empty string.
*/

#include "components/Text.hpp"
#include <iostream>
#include <utility>

/**
 * @brief Constructor for the Text component.
 *
 * This constructor initializes the text component with the given text value.
 *
 * @param text The initial text for the component.
 * @param fontFile
 * @param characterSize
 */
Text::Text(const std::string& text, const std::string& fontFile,
           const unsigned int characterSize)
    : _initText(text), _fontFile(fontFile), _charSize(characterSize), _initSize(characterSize) {}

/**
 * @brief Destructor for the Text component.
 *
 * This destructor cleans up any resources used by the text component.
 */
Text::~Text() {}

/**
 * @brief Get the text of the Text component.
 *
 * This function retrieves the current text of the component.
 *
 * @return The current text of the component.
 */
std::string Text::getString() const {
    return this->_initText;
}

/**
 * @brief Set the text of the Text component.
 *
 * This function sets a new text value for the component.
 *
 * @param text The new text to be set.
 */
void Text::setString(const std::string& text) {
    this->_initText = text;
}

/**
 * @brief Get the font of the Text component.
 *
 * This function retrieves the font used by the text component.
 *
 * @return The font used by the text component.
 */
sf::Font& Text::getFont() {
    return this->_font;
}

/**
 * @brief Get the character size of the Text component.
 *
 * This function retrieves the character size of the text component.
 *
 * @return The character size of the text component.
 */
unsigned int Text::getCharacterSize() const {
    return this->_charSize;
}

/**
 * @brief Set the character size of the Text component.
 *
 * This function sets the character size of the text component.
 *
 * @param characterSize The new character size to set.
 */
void Text::setCharacterSize(unsigned int characterSize) {
    this->_charSize = characterSize;
}

/**
 * @brief Get the initial character size of the Text component.
 *
 * This function retrieves the initial character size of the text component.
 *
 * @return The initial character size of the text component.
 */
unsigned int Text::getInitCharacterSize() const {
    return this->_initSize;
}

/**
 * @brief Get whether the Text component is loaded.
 *
 * This function checks if the Text component has been initialized.
 *
 * @return True if the Text is loaded, false otherwise.
 */
bool Text::getIsLoaded() const {
    return this->_isLoad;
}

/**
 * @brief Get the font file of the Text component.
 *
 * This function retrieves the font file used by the text component.
 *
 * @return The font file used by the text component.
 */
std::string Text::getFontFile() const {
    return this->_fontFile;
}

/**
 * @brief Set whether the Text component is loaded.
 *
 * This function sets the loaded state of the Text component.
 *
 * @param isLoaded The new loaded state of the component.
 */
void Text::setFontFile(std::string font) {
    this->_fontFile = font;
}

/**
 * @brief Set whether the Text component is loaded.
 *
 * This function sets the loaded state of the Text component.
 *
 * @param isLoaded The new loaded state of the component.
 */
void Text::setIsLoaded(const bool isLoaded) {
    this->_isLoad = isLoaded;
}

/**
 * @brief Get the sf::Text object of the Text component.
 *
 * This function retrieves the sf::Text object used by the text component.
 *
 * @return The sf::Text object used by the text component.
 */
sf::Text& Text::getText() {
    return this->_text;
}

/**
 * @brief Display the Text component information.
 *
 * This function displays a message indicating that the text component is being
 * displayed.
 */
void Text::display() const {
    std::cout << "Text component displayed!" << std::endl;
}
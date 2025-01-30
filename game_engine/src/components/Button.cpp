/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Button.cpp
**
** The Button class represents a UI button with a text label and a size.
** It holds a `text` as a string and `size` as a `std::pair<double, double>` for
the button's
** width and height.
** The constructor allows initializing these attributes with default values.
*/

#include "components/Button.hpp"

/**
 * @brief Constructor for the Button component.
 *
 * This constructor initializes the Button component with the specified text and
 * size.
 *
 * @param text A string representing the text on the button.
 * @param size A pair of doubles representing the size of the button (width,
 * height).
 */

Button::Button(std::string text, std::string fontFile,
               unsigned int characterSize)
    : _initText(text), _fontFile(fontFile), _charSize(characterSize) {}

/**
 * @brief Destructor for the Button component.
 *
 * This destructor cleans up any resources used by the Button component.
 */
Button::~Button() {}

/**
 * @brief Get the button shape of the Button component.
 *
 * This function returns a reference to the RectangleShape representing the
 * button.
 *
 * @return A reference to an sf::RectangleShape.
 */
sf::RectangleShape& Button::getButton() {
    return this->_button;
}

/**
 * @brief Get the text object of the Button component.
 *
 * This function retrieves the text object displayed on the button.
 *
 * @return A reference to an sf::Text object representing the button's text.
 */
sf::Text& Button::getText() {
    return this->_text;
}

/**
 * @brief Get the string displayed on the Button.
 *
 * This function retrieves the initial text of the button.
 *
 * @return A string representing the text on the button.
 */
std::string Button::getString() const {
    return this->_initText;
}

/**
 * @brief Set the string displayed on the Button.
 *
 * This function updates the text displayed on the button.
 *
 * @param text A string representing the new text to display on the button.
 */
void Button::setString(std::string text) {
    this->_initText = text;
}

/**
 * @brief Get the font file used by the Button.
 *
 * This function retrieves the path to the font file associated with the
 * button's text.
 *
 * @return A string representing the font file path.
 */
std::string Button::getFontFile() const {
    return this->_fontFile;
}

/**
 * @brief Get the font object used by the Button.
 *
 * This function returns a reference to the font used by the button.
 *
 * @return A reference to an sf::Font object.
 */
sf::Font& Button::getFont() {
    return this->_font;
}

/**
 * @brief Get the character size of the Button text.
 *
 * This function retrieves the size of the characters used for the button's
 * text.
 *
 * @return An unsigned integer representing the character size.
 */
unsigned int Button::getCharacterSize() const {
    return this->_charSize;
}

/**
 * @brief Get the size of the Button component.
 *
 * This function retrieves the size of the button as a pair of doubles.
 *
 * @return A pair of doubles representing the size of the button (width,
 * height).
 */
std::pair<double, double> Button::getSize() const {
    return this->_size;
}

/**
 * @brief Set the load status of the Button.
 *
 * This function sets the load status of the button.
 *
 * @param isLoaded A boolean indicating whether the button is loaded.
 */
void Button::setIsLoaded(bool isLoaded) {
    this->_isLoad = isLoaded;
}

/**
 * @brief Get the load status of the Button.
 *
 * This function retrieves the load status of the button.
 *
 * @return A boolean indicating if the button is loaded.
 */
bool Button::getIsLoaded() const {
    return this->_isLoad;
}

/**
 * @brief Set function for callback.
 *
 * This function sets the callback state of the Slider component.
 * @param callback An std::function object representing the function to
 * callback.
 */
void Button::setCallback(std::function<void()> callback) {
    _callback = callback;
}

/**
 * @brief Execute function callback.
 *
 * This function call the function in callback of the Slider component.
 */
void Button::executeCallback() {
    if (_callback) {
        _callback();
    }
}

/**
 * @brief Display the Button component information.
 *
 * This function displays a message indicating that the Button component is
 * being displayed.
 */
void Button::display() const {
    std::cout << "Button component displayed!" << std::endl;
}

/**
 * @brief Check if the button is hovered.
 *
 * This function checks if the given mouse position is over the button.
 *
 * @param mousePos A vector representing the mouse position (x, y).
 * @return True if the button is hovered, false otherwise.
 */
bool Button::isHovered(sf::Vector2i mousePos) {
    return this->_button.getGlobalBounds().contains(mousePos.x, mousePos.y);
}

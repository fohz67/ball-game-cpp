/*
** EPITECH PROJECT, 2024
** B-CPP-500-TLS-5-2-rtype-anastasia.bouby
** File description:
** Implements the `textSystem` function, which handles the rendering and
** interaction of text components within the game engine.
** Responsibility:
** - Check if an entity has text and position components
** - Load text resources if not already loaded
** - Render the text on the window
** - Update the text's properties based on game logic
*/

#include <components/Text.hpp>
#include "System.hpp"

/**
 * @brief Loads the text component of an entity if it is not already loaded.
 * 
 * This function checks if the text component is loaded. If not, it loads the font from file,
 * sets the font, string, character size, position, and color of the text. Finally, it marks
 * the text component as loaded. If the text component is already loaded, it updates the text.
 * 
 * @param entity The entity containing the text component.
 * @param textComp The text component to be loaded.
 */
void GameEngine::System::loadText(GameEngine::Entity& entity, auto& textComp) {
    if (!textComp.getIsLoaded()) {
        textComp.getFont().loadFromFile(textComp.getFontFile());
        textComp.getText().setFont(textComp.getFont());
        textComp.getText().setString(textComp.getString());
        textComp.getText().setCharacterSize(textComp.getCharacterSize());
        setPosition(entity, textComp.getText());
        setColor(entity, textComp.getText());
        sf::FloatRect bounds = textComp.getText().getLocalBounds();
        textComp.getText().setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
        textComp.setIsLoaded(true);
    } else {
        updateText(entity, textComp.getString());
    }
}

/**
 * @brief Renders the text component of an entity on the window.
 * 
 * This function checks if the entity has both text and position components. If so, it loads
 * the text component and then draws the text on the window. If the position component has
 * multiple positions, it draws the text at each position. Otherwise, it draws the text at
 * the single position.
 * 
 * @param window The render window where the text will be drawn.
 * @param entity The entity containing the text and position components.
 */
void GameEngine::System::textSystem(sf::RenderWindow& window,
                                    GameEngine::Entity& entity) {
    if (entity.hasComponent<Text>() && entity.hasComponent<Position>()) {
        auto& textComp = entity.getComponent<Text>();
        loadText(entity, textComp);
        if (entity.getComponent<Position>().getPositions().size() > 1) {
            auto& positionComp = entity.getComponent<Position>();
            for (auto& position : positionComp.getPositions()) {
                textComp.getText().setPosition(position.first, position.second);
                window.draw(textComp.getText());
            }
        } else {
            window.draw(textComp.getText());
        }
    }
}
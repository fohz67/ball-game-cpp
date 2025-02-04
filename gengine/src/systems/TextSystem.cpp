#include <components/Text.hpp>
#include "System.hpp"

void GEngine::System::loadText(GEngine::Entity& entity, auto& textComp) {
    if (!textComp.isLoaded()) {
        unsigned int highResSize = textComp.getCharacterSize() * 5;
        float        scaleFactor = 1.0f / 5.0f;

        textComp.getText().setCharacterSize(highResSize);
        textComp.getText().setScale(scaleFactor, scaleFactor);
        textComp.getFont().loadFromFile(textComp.getFontFile());
        textComp.getText().setFont(textComp.getFont());
        textComp.getText().setString(textComp.getString());

        if (textComp.getCentering() == 1) {
            sf::FloatRect bounds = textComp.getText().getLocalBounds();
            textComp.getText().setOrigin(
                bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
        }
        if (textComp.getCentering() == 2) {
            sf::FloatRect bounds = textComp.getText().getLocalBounds();
            textComp.getText().setOrigin(bounds.width, 0);
        }

        setPosition(entity, textComp.getText());
        setColor(entity, textComp.getText());

        textComp.setLoaded(true);
    } else {
        updateText(entity, textComp.getString());
    }
}

void GEngine::System::textSystem(sf::RenderWindow& window, GEngine::Entity& entity) {
    if (entity.hasComponent<Text>() && entity.hasComponent<Position>()) {
        auto& textComp = entity.getComponent<Text>();

        loadText(entity, textComp);

        auto& positionComp = entity.getComponent<Position>();
        if (positionComp.getPositions().size() > 1) {
            for (auto& position : positionComp.getPositions()) {
                textComp.getText().setPosition(position.first, position.second);
                window.draw(textComp.getText());
            }
        } else {
            window.draw(textComp.getText());
        }
    }
}

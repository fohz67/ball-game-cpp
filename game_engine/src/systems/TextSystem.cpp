#include <components/Text.hpp>
#include <unordered_map>

#include "System.hpp"

void GameEngine::System::loadText(GameEngine::Entity& entity, auto& textComp)
{
    static std::unordered_map<std::string, sf::Font> fontCache;

    if (!textComp.isLoaded())
    {
        textComp.getText().setCharacterSize(textComp.getCharacterSize());

        if (fontCache.find(textComp.getFontFile()) == fontCache.end())
        {
            sf::Font font;

            if (font.loadFromFile(textComp.getFontFile()))
            {
                fontCache[textComp.getFontFile()] = std::move(font);
            }
        }

        textComp.getText().setFont(fontCache[textComp.getFontFile()]);
        textComp.getText().setString(textComp.getString());

        if (textComp.getCentering() == 1)
        {
            sf::FloatRect bounds = textComp.getText().getLocalBounds();

            textComp.getText().setOrigin(bounds.left + bounds.width / 2,
                                         bounds.top + bounds.height / 2);
        }

        if (textComp.getCentering() == 2)
        {
            sf::FloatRect bounds = textComp.getText().getLocalBounds();

            textComp.getText().setOrigin(bounds.width, 0);
        }

        setPosition(entity, textComp.getText());
        setColor(entity, textComp.getText());

        textComp.setLoaded(true);
    }
    else
    {
        updateText(entity, textComp.getString());
    }
}

void GameEngine::System::textSystem(sf::RenderWindow& window,
                                    GameEngine::Entity& entity,
                                    float deltaTime)
{
    if (entity.hasComponent<Text>() && entity.hasComponent<Position>())
    {
        auto& textComp = entity.getComponent<Text>();

        loadText(entity, textComp);

        auto& positionComp = entity.getComponent<Position>();

        window.draw(textComp.getText());
    }
}

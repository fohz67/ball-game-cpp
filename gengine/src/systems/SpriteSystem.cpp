#include <components/Sprite.hpp>
#include "System.hpp"

void GEngine::System::loadSprite(GEngine::Entity& entity, auto& spriteComp,
                                 auto& textureComp) {
    if (!spriteComp.isLoaded()) {
        if (textureComp.getTextureRect().size() == 4) {
            const auto& textureRect = textureComp.getTextureRect();
            spriteComp.getSprite().setTextureRect(
                sf::IntRect(textureRect[0], textureRect[1], textureRect[2],
                            textureRect[3]));
        }

        spriteComp.getSprite().setTexture(textureComp.getTexture());
        setPosition(entity, spriteComp.getSprite());

        if (spriteComp.getSize().first != -1 &&
            spriteComp.getSize().second != -1) {
            spriteComp.getSprite().setScale(spriteComp.getSize().first,
                                            spriteComp.getSize().second);
        }

        setColor(entity, spriteComp.getSprite());
        spriteComp.setLoaded(true);
    }
}

void GEngine::System::spriteSystem(sf::RenderWindow& window,
                                   GEngine::Entity& entity) {
    if (entity.hasComponent<Sprite>() && entity.hasComponent<Texture>()) {
        auto& spriteComp = entity.getComponent<Sprite>();
        auto& textureComp = entity.getComponent<Texture>();

        if (!textureComp.isLoaded()) {
            textureComp.getTexture().loadFromFile(textureComp.getTexturePath());
            textureComp.setLoaded(true);
        }

        loadSprite(entity, spriteComp, textureComp);

        auto& positionComp = entity.getComponent<Position>();
        if (positionComp.getPositions().size() > 1) {
            for (auto& position : positionComp.getPositions()) {
                spriteComp.getSprite().setPosition(position.first,
                                                   position.second);
                window.draw(spriteComp.getSprite());
            }
        } else {
            window.draw(spriteComp.getSprite());
        }
    }
}

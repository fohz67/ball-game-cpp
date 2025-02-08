#include <components/Sprite.hpp>
#include <unordered_map>

#include "System.hpp"

void GameEngine::System::loadSprite(GameEngine::Entity& entity, auto& spriteComp, auto& textureComp)
{
    static std::unordered_map<std::string, sf::Texture> textureCache;

    if (!spriteComp.isLoaded())
    {
        if (textureCache.find(textureComp.getTexturePath()) == textureCache.end())
        {
            sf::Texture texture;

            if (texture.loadFromFile(textureComp.getTexturePath()))
            {
                textureCache[textureComp.getTexturePath()] = std::move(texture);
            }
        }

        spriteComp.getSprite().setTexture(textureCache[textureComp.getTexturePath()]);

        if (textureComp.getTextureRect().size() == 4)
        {
            const auto& textureRect = textureComp.getTextureRect();
            spriteComp.getSprite().setTextureRect(
                sf::IntRect(textureRect[0], textureRect[1], textureRect[2], textureRect[3]));
        }

        if (spriteComp.getSize().first != -1 && spriteComp.getSize().second != -1)
        {
            spriteComp.getSprite().setScale(spriteComp.getSize().first,
                                            spriteComp.getSize().second);
        }

        setPosition(entity, spriteComp.getSprite());
        setColor(entity, spriteComp.getSprite());
        spriteComp.setLoaded(true);
    }
}

void GameEngine::System::spriteSystem(sf::RenderWindow& window,
                                      GameEngine::Entity& entity,
                                      float deltaTime)
{
    if (entity.hasComponent<Sprite>() && entity.hasComponent<Texture>())
    {
        auto& spriteComp = entity.getComponent<Sprite>();
        auto& textureComp = entity.getComponent<Texture>();
        auto& positionComp = entity.getComponent<Position>();

        loadSprite(entity, spriteComp, textureComp);

        static std::unordered_map<uint32_t, std::pair<double, double>> lastPositions;
        auto newPos = positionComp.getPosition();

        if (lastPositions[entity.getEntityId()] != newPos)
        {
            spriteComp.getSprite().setPosition(newPos.first, newPos.second);
            lastPositions[entity.getEntityId()] = newPos;
        }

        window.draw(spriteComp.getSprite());
    }
}

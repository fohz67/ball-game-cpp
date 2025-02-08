#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <any>
#include <components/Color.hpp>
#include <components/Position.hpp>
#include <memory>

#include "Entity.hpp"

namespace GameEngine
{

enum class UpdateType
{
    Position,
    Text,
    TextSize,
    TextFont,
    Texture,
    ShapeSize
};

class System
{
   public:
    // Constructor / Destructor
    System() = default;
    ~System() = default;

    // Main Methods
    void render(sf::RenderWindow& window, std::map<double, Entity>& entities, float deltaTime);

    // Set Methods
    template <typename Drawable>
    void setColor(Entity& entity, Drawable& drawable);
    template <typename Drawable>
    void setPosition(Entity& entity, Drawable& drawable);

    // Update Methods
    void update(const double id,
                std::map<double, Entity>& entities,
                UpdateType type,
                const std::any& value);
    template <typename Drawable>
    void updatePosition(Entity& entity, Drawable& drawable, const std::pair<double, double>& pos);
    void updateEntityPosition(int id,
                              std::map<double, Entity>& entities,
                              const std::pair<double, double>& pos);
    void updateTexture(Entity& entity, std::string& texture);
    void updateText(Entity& entity, const std::string& text);
    void updateTextSize(int id, std::map<double, Entity>& entities, unsigned int textSize);
    void updateTextFont(Entity& entity, const std::string& font);
    void updateShapeSize(Entity& entity, double radius);

    // Load Methods
    void loadSprite(Entity& entity, auto& spriteComp, auto& textureComp);
    void loadText(Entity& entity, auto& textComp);
    void loadRectangle(Entity& entity, auto& shapeComp);
    void loadCircle(Entity& entity, auto& shapeComp);

    // System Methods
    void spriteSystem(sf::RenderWindow& window, Entity& entity, float deltaTime);
    void textSystem(sf::RenderWindow& window, Entity& entity, float deltaTime);
    void shapeSystem(sf::RenderWindow& window, Entity& entity, float deltaTime);
    void buttonSystem(sf::RenderWindow& window, Entity& entity, float deltaTime);
    void optionButtonSystem(sf::RenderWindow& window, Entity& entity, float deltaTime);
    void buttonRectSystem(sf::RenderWindow& window, Entity& entity, float deltaTime);
    void linkSystem(int id,
                    std::map<double, Entity>& entities,
                    std::pair<double, double> newLinkedEntityPos);
    void sliderSystem(sf::RenderWindow& window,
                      Entity& entity,
                      std::map<double, Entity>& entities,
                      float deltaTime);
};

template <typename Drawable>
void System::setColor(Entity& entity, Drawable& drawable)
{
    if (entity.hasComponent<Color>() && entity.getComponent<Color>().getColor().size() == 4)
    {
        const auto& color = entity.getComponent<Color>().getColor();

        if constexpr (std::is_same_v<Drawable, sf::Sprite>)
        {
            drawable.setColor(sf::Color(color[0], color[1], color[2], color[3]));
        }
        else if constexpr (std::is_same_v<Drawable, sf::Text> ||
                           std::is_same_v<Drawable, sf::RectangleShape> ||
                           std::is_same_v<Drawable, sf::CircleShape>)
        {
            drawable.setFillColor(sf::Color(color[0], color[1], color[2], color[3]));
        }
    }
}

template <typename Drawable>
void System::setPosition(Entity& entity, Drawable& drawable)
{
    if (entity.hasComponent<Position>())
    {
        auto& positionComp = entity.getComponent<Position>();

        drawable.setPosition(positionComp.getPositionX(), positionComp.getPositionY());
    }
}

template <typename Drawable>
void System::updatePosition(Entity& entity,
                            Drawable& drawable,
                            const std::pair<double, double>& pos)
{
    if (entity.hasComponent<Position>())
    {
        auto& positionComp = entity.getComponent<Position>();

        positionComp.setPositionX(pos.first);
        positionComp.setPositionY(pos.second);

        drawable.setPosition(pos.first, pos.second);
    }
}

}  // namespace GameEngine

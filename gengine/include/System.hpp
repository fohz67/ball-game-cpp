#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <any>
#include <components/Color.hpp>
#include <components/Position.hpp>
#include <memory>
#include "Entity.hpp"

namespace GEngine {

enum class UpdateType { Position, Text, TextSize, TextFont, Texture, ShapeSize };

class System {
  public:
    // Constructor / Destructor
    System()  = default;
    ~System() = default;

    // Methods
    void render(sf::RenderWindow& window, std::map<double, Entity>& entities);
    void update(int                       id,
                std::map<double, Entity>& entities,
                UpdateType                type,
                const std::any&           value,
                int                       posId = 0);

  private:
    std::string fontFile;

    // Color
    template <typename Drawable> void setColor(Entity& entity, Drawable& drawable);

    // Position
    template <typename Drawable> void setPosition(Entity& entity, Drawable& drawable);
    template <typename Drawable>
    void updatePosition(Entity&                        entity,
                        Drawable&                      drawable,
                        const std::pair<float, float>& pos,
                        const int&                     posId);
    void updateEntityPosition(int                            id,
                              std::map<double, Entity>&      entities,
                              const std::pair<float, float>& pos,
                              int                            posId);

    // Texture
    void updateTexture(Entity& entity, std::string& texture);

    // Sprite
    void loadSprite(Entity& entity, auto& spriteComp, auto& textureComp);
    void spriteSystem(sf::RenderWindow& window, Entity& entity);

    // Link
    void linkSystem(int                       id,
                    std::map<double, Entity>& entities,
                    std::pair<float, float>   newLinkedEntityPos,
                    int                       posId);

    // Text
    void loadText(Entity& entity, auto& textComp);
    void updateText(Entity& entity, const std::string& text);
    void updateTextSize(int id, std::map<double, Entity>& entities, unsigned int textSize);
    void updateTextFont(Entity& entity, const std::string& font);
    void textSystem(sf::RenderWindow& window, Entity& entity);

    // Shape
    void loadRectangle(Entity& entity, auto& shapeComp);
    void loadCircle(Entity& entity, auto& shapeComp);
    void shapeSystem(sf::RenderWindow& window, Entity& entity);
    void updateShapeSize(Entity& entity, double radius);

    // Button
    void buttonSystem(sf::RenderWindow& window, Entity& entity);
    void optionButtonSystem(sf::RenderWindow& window, Entity& entity);
    void buttonRectSystem(sf::RenderWindow& window, Entity& entity);

    // Slider
    void sliderSystem(sf::RenderWindow& window, Entity& entity, std::map<double, Entity>& entities);
};

template <typename Drawable> void System::setColor(Entity& entity, Drawable& drawable) {
    if (entity.hasComponent<Color>() && entity.getComponent<Color>().getColor().size() == 4) {
        const auto& color = entity.getComponent<Color>().getColor();

        if constexpr (std::is_same_v<Drawable, sf::Sprite>) {
            drawable.setColor(sf::Color(color[0], color[1], color[2], color[3]));
        } else if constexpr (std::is_same_v<Drawable, sf::Text> ||
                             std::is_same_v<Drawable, sf::RectangleShape> ||
                             std::is_same_v<Drawable, sf::CircleShape>) {
            drawable.setFillColor(sf::Color(color[0], color[1], color[2], color[3]));
        }
    }
}

template <typename Drawable> void System::setPosition(Entity& entity, Drawable& drawable) {
    if (entity.hasComponent<Position>()) {
        auto& positionComp = entity.getComponent<Position>();

        drawable.setPosition(positionComp.getPositionX(0), positionComp.getPositionY(0));
    }
}

template <typename Drawable>
void System::updatePosition(Entity&                        entity,
                            Drawable&                      drawable,
                            const std::pair<float, float>& pos,
                            const int&                     posId) {
    if (entity.hasComponent<Position>()) {
        auto& positionComp = entity.getComponent<Position>();

        positionComp.setPositionX(posId, pos.first);
        positionComp.setPositionY(posId, pos.second);

        drawable.setPosition(pos.first, pos.second);
    }
}

} // namespace GEngine

#include <components/Button.hpp>
#include <components/ButtonRect.hpp>
#include <components/OptionButton.hpp>
#include <components/Slider.hpp>

#include "System.hpp"

void GameEngine::System::buttonSystem(sf::RenderWindow& window,
                                      GameEngine::Entity& entity,
                                      float deltaTime)
{
    if (entity.hasComponent<Button>() && entity.hasComponent<Position>())
    {
        auto& buttonComp = entity.getComponent<Button>();
        auto& positionComp = entity.getComponent<Position>();

        if (!buttonComp.isLoaded())
        {
            buttonComp.getFont().loadFromFile(buttonComp.getFontFile());
            buttonComp.getText().setFont(buttonComp.getFont());
            buttonComp.getText().setString(buttonComp.getString());
            buttonComp.getText().setCharacterSize(buttonComp.getCharacterSize());
            buttonComp.getText().setFillColor(sf::Color::White);

            sf::FloatRect textBounds = buttonComp.getText().getLocalBounds();
            float padding = 10.f;

            buttonComp.getButton().setSize(
                sf::Vector2f(textBounds.width + 2 * padding, textBounds.height + 2 * padding));
            buttonComp.getButton().setFillColor(sf::Color::Transparent);
            buttonComp.getButton().setPosition(positionComp.getPositionX(),
                                               positionComp.getPositionY());
            buttonComp.getText().setOrigin(textBounds.left + textBounds.width / 2,
                                           textBounds.top + textBounds.height / 2);
            buttonComp.getText().setPosition(
                buttonComp.getButton().getPosition().x + buttonComp.getButton().getSize().x / 2,
                buttonComp.getButton().getPosition().y + buttonComp.getButton().getSize().y / 2);

            buttonComp.setLoaded(true);
        }

        static std::map<GameEngine::Entity*, bool> wasPressedMap;

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::FloatRect buttonBounds = buttonComp.getButton().getGlobalBounds();

        if (buttonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
            bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

            if (isPressed && !wasPressedMap[&entity])
            {
                buttonComp.executeCallback();
                wasPressedMap[&entity] = true;
            }
            else if (!isPressed)
            {
                wasPressedMap[&entity] = false;
            }
        }

        window.draw(buttonComp.getButton());
        window.draw(buttonComp.getText());
    }
}

void GameEngine::System::optionButtonSystem(sf::RenderWindow& window,
                                            GameEngine::Entity& entity,
                                            float deltaTime)
{
    if (entity.hasComponent<OptionButton>() && entity.hasComponent<Position>())
    {
        auto& buttonComp = entity.getComponent<OptionButton>();
        auto& positionComp = entity.getComponent<Position>();

        if (!buttonComp.isLoaded())
        {
            sf::RectangleShape buttonShape;

            buttonShape.setSize({static_cast<float>(buttonComp.getSize().first),
                                 static_cast<float>(buttonComp.getSize().second)});
            buttonShape.setPosition(positionComp.getPositionX(), positionComp.getPositionY());
            buttonShape.setOutlineThickness(2);

            if (entity.hasComponent<Color>() && entity.getComponent<Color>().getColor().size() == 4)
            {
                auto& colorComp = entity.getComponent<Color>();
                const auto color = colorComp.getColor();

                buttonComp.getShape().setOutlineColor(
                    sf::Color(color[0], color[1], color[2], color[3]));
                buttonShape.setFillColor(sf::Color::Transparent);
            }

            buttonComp.setShape(buttonShape);
            buttonComp.setLoaded();
        }

        static std::map<GameEngine::Entity*, bool> wasPressedMap;

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::FloatRect buttonBounds = buttonComp.getShape().getGlobalBounds();

        if (buttonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
            bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

            if (isPressed && !wasPressedMap[&entity])
            {
                buttonComp.setChecked();
                buttonComp.executeCallback();
                wasPressedMap[&entity] = true;
            }
            else if (!isPressed)
            {
                wasPressedMap[&entity] = false;
            }
        }

        if (buttonComp.isChecked())
        {
            buttonComp.getShape().setFillColor(sf::Color::White);
        }
        else
        {
            buttonComp.getShape().setFillColor(sf::Color::Transparent);
        }

        window.draw(buttonComp.getShape());
    }
}

void GameEngine::System::sliderSystem(sf::RenderWindow& window,
                                      GameEngine::Entity& entity,
                                      std::map<double, Entity>& entities,
                                      float deltaTime)
{
    GameEngine::System system;
    if (entity.hasComponent<Slider>() && entity.hasComponent<Position>())
    {
        auto& sliderComp = entity.getComponent<Slider>();
        auto& positionComp = entity.getComponent<Position>();

        if (!sliderComp.isLoaded())
        {
            sf::RectangleShape barShape;

            barShape.setPosition(positionComp.getPositionX(), positionComp.getPositionY());
            barShape.setSize({static_cast<float>(sliderComp.getSize().first),
                              static_cast<float>(sliderComp.getSize().second)});
            barShape.setOutlineThickness(5);
            barShape.setOutlineColor(sf::Color::Transparent);

            sf::CircleShape cursorShape;
            cursorShape.setRadius(9.f);

            if (entity.hasComponent<Color>() && entity.getComponent<Color>().getColor().size() == 4)
            {
                auto& colorComp = entity.getComponent<Color>();
                const auto color = colorComp.getColor();

                barShape.setFillColor(sf::Color(color[0], color[1], color[2], color[3]));
                cursorShape.setFillColor(sf::Color(color[0], color[1], color[2], color[3]));
            }

            float normalizedValue = (sliderComp.getValue() - sliderComp.getMinValue()) /
                                    (sliderComp.getMaxValue() - sliderComp.getMinValue());
            float cursorX = barShape.getPosition().x + normalizedValue * barShape.getSize().x;

            cursorShape.setPosition(cursorX - cursorShape.getRadius(),
                                    barShape.getPosition().y - 7);

            sliderComp.setBarShape(barShape);
            sliderComp.setCursorShape(cursorShape);
            sliderComp.setLoaded();
        }

        static std::map<GameEngine::Entity*, bool> wasPressedMap;

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::FloatRect barBounds = sliderComp.getBarShape().getGlobalBounds();

        if (barBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
            bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

            if (isPressed && !wasPressedMap[&entity])
            {
                wasPressedMap[&entity] = true;
            }
            else if (!isPressed)
            {
                wasPressedMap[&entity] = false;
            }

            if (wasPressedMap[&entity])
            {
                float newValue = (mousePos.x - barBounds.left) / barBounds.width;
                newValue = std::clamp(newValue, 0.f, 1.f);

                float sliderValue =
                    sliderComp.getMinValue() +
                    newValue * (sliderComp.getMaxValue() - sliderComp.getMinValue());
                sliderComp.setValue(sliderValue);

                float cursorX = barBounds.left + newValue * barBounds.width;
                sliderComp.getCursorShape().setPosition(
                    cursorX - sliderComp.getCursorShape().getRadius(),
                    sliderComp.getCursorShape().getPosition().y);
                sliderComp.executeCallback(sliderComp.getValue());

                system.update(entity.getEntityId(),
                              entities,
                              UpdateType::Text,
                              std::to_string(sliderComp.getValue()));
            }
        }

        window.draw(sliderComp.getBarShape());
        window.draw(sliderComp.getCursorShape());
    }
}

void GameEngine::System::buttonRectSystem(sf::RenderWindow& window,
                                          GameEngine::Entity& entity,
                                          float deltaTime)
{
    if (entity.hasComponent<ButtonRect>() && entity.hasComponent<Position>())
    {
        auto& buttonRectComp = entity.getComponent<ButtonRect>();
        auto& positionComp = entity.getComponent<Position>();

        if (!buttonRectComp.isLoaded())
        {
            buttonRectComp.getButtonRect().setSize(
                sf::Vector2f(buttonRectComp.getSize().first, buttonRectComp.getSize().second));
            buttonRectComp.getButtonRect().setPosition(positionComp.getPositionX(),
                                                       positionComp.getPositionY());

            if (!buttonRectComp.isShowOutline())
            {
                buttonRectComp.getButtonRect().setFillColor(buttonRectComp.getColor());
            }
            else
            {
                buttonRectComp.getButtonRect().setOutlineThickness(2);
                buttonRectComp.getButtonRect().setOutlineColor(buttonRectComp.getColor());
                buttonRectComp.getButtonRect().setFillColor(sf::Color::Transparent);
            }

            buttonRectComp.setLoaded(true);
        }

        static std::map<GameEngine::Entity*, bool> wasPressedMap;

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::FloatRect buttonRectBounds = buttonRectComp.getButtonRect().getGlobalBounds();

        if (buttonRectBounds.contains(static_cast<float>(mousePos.x),
                                      static_cast<float>(mousePos.y)))
        {
            bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

            if (isPressed && !wasPressedMap[&entity])
            {
                buttonRectComp.executeCallback();
                wasPressedMap[&entity] = true;
            }
            else if (!isPressed)
            {
                wasPressedMap[&entity] = false;
            }
        }

        window.draw(buttonRectComp.getButtonRect());
    }
}

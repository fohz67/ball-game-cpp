#include "System.hpp"

void GameEngine::System::render(sf::RenderWindow& window,
                                std::map<double, Entity>& entities,
                                float deltaTime)
{
    for (auto& [id, entity] : entities)
    {
        spriteSystem(window, entity, deltaTime);
        textSystem(window, entity, deltaTime);
        buttonSystem(window, entity, deltaTime);
        buttonRectSystem(window, entity, deltaTime);
        optionButtonSystem(window, entity, deltaTime);
        sliderSystem(window, entity, entities, deltaTime);
        shapeSystem(window, entity, deltaTime);
    }
}

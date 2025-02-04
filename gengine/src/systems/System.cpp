#include "System.hpp"

void GEngine::System::render(sf::RenderWindow& window, std::map<double, Entity>& entities) {
    for (auto& [id, entity] : entities) {
        // spriteSystem(window, entity);
        textSystem(window, entity);
        // buttonSystem(window, entity);
        // buttonRectSystem(window, entity);
        // optionButtonSystem(window, entity);
        // sliderSystem(window, entity, entities);
        shapeSystem(window, entity);
    }
}

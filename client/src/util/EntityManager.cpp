#include "util/EntityManager.hpp"
#include <components/Link.hpp>
#include <components/Position.hpp>
#include <components/Shape.hpp>
#include <components/Sprite.hpp>
#include <components/Text.hpp>
#include <components/Texture.hpp>
#include "System.hpp"

EntityManager& EntityManager::get() {
    static EntityManager instance;
    return instance;
}

void EntityManager::setEntities(std::map<int, GameEngine::Entity> entities) {
    entities = entities;
}

std::map<int, GameEngine::Entity>& EntityManager::getEntities() {
    return entities;
}

void EntityManager::compareEntities(int id,
                                    std::map<std::string, std::any> components,
                                    std::pair<float, float> updatePosition) {
    std::lock_guard<std::mutex> lock(mutex);
    GameEngine::System system;
    if (auto search = entities.find(id); search != entities.end()) {
        system.update(id, entities, GameEngine::UpdateType::Position,
                      updatePosition);
    } else {
        createEntity(id, components);
    }
}

void EntityManager::createEntity(int id, std::map<std::string, std::any> components) {
    if (components.empty()) return;

    std::lock_guard<std::mutex> lock(mutex);
    auto newEntity = GameEngine::Entity(id);

    const auto textureIt = components.find("Texture");
    const auto textureRectIt = components.find("TextureRect");
    const auto sizeIt = components.find("Size");
    const auto positionIt = components.find("Position");

    if (textureIt != components.end()) {
        const auto& texture = std::any_cast<std::string>(textureIt->second);

        if (textureRectIt != components.end()) {
            const auto& textureRect = std::any_cast<std::vector<int>>(textureRectIt->second);

            if (sizeIt != components.end()) {
                const auto& size = std::any_cast<std::pair<float, float>>(sizeIt->second);
                newEntity.addComponent(Shape(Rectangle, size));
                newEntity.addComponent(Texture(texture, textureRect));
            } else {
                newEntity.addComponent(Sprite());
                newEntity.addComponent(Texture(texture, textureRect));
            }
        } else {
            newEntity.addComponent(Sprite());
            newEntity.addComponent(Texture(texture));
        }
    }

    if (positionIt != components.end()) {
        const auto& position = std::any_cast<std::pair<float, float>>(positionIt->second);
        newEntity.addComponent(Position({position}));
    }

    entities.emplace(id, std::move(newEntity));
}

void EntityManager::removeEntity(int id) {
    std::lock_guard<std::mutex> lock(mutex);
    entities.erase(id);
}

void EntityManager::clearEntities() {
    std::lock_guard<std::mutex> lock(mutex);
    entities.clear();
}

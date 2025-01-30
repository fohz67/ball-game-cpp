/*
** EPITECH PROJECT, 2024
** B-CPP-500-TLS-5-2-rtype-anastasia.bouby
** File description:
** Implements the `linkSystem` function, which manages the linking of entities
** within the game engine.
** Responsibility:
** - Check if entities have linkable components
** - Establish and manage links between entities
** - Update linked entities based on their relationships
*/

#include <components/Link.hpp>
#include <components/Sprite.hpp>
#include <components/Text.hpp>
#include "System.hpp"

/**
 * @brief Links the position of two entities.
 * 
 * This function links the position of two entities. It checks if the entity has a link component.
 * If so, it gets the linked entity and calculates the distance between the two entities. It then
 * updates the position of the entity based on the distance.
 * 
 * @param id The id of the entity.
 * @param entities The map of entities.
 * @param newLinkedEntityPos The new position of the linked entity.
 * @param posId The position id.
 */
void GameEngine::System::linkSystem(int id,
                                    std::map<int, GameEngine::Entity>& entities,
                                    std::pair<float, float> newLinkedEntityPos,
                                    const int posId) {
    for (auto& [_, entity] : entities) {
        if (entity.hasComponent<Link>() &&
            entity.getComponent<Link>().getId() == id) {
            GameEngine::Entity entityLinked = entities[id];
            auto oldLinkedEntityPos = entityLinked.getComponent<Position>();
            const std::pair dist = {newLinkedEntityPos.first -
                                        oldLinkedEntityPos.getPositionX(posId),
                                    newLinkedEntityPos.second -
                                        oldLinkedEntityPos.getPositionY(posId)};
            auto entityPos = entity.getComponent<Position>();
            const std::pair newPos = {entityPos.getPositionX(0) + dist.first,
                                      entityPos.getPositionY(0) + dist.second};
            if (entity.hasComponent<Sprite>()) {
                updatePos(entity, entity.getComponent<Sprite>().getSprite(),
                          newPos, 0);
            }
            if (entity.hasComponent<Text>()) {
                updatePos(entity, entity.getComponent<Text>().getText(), newPos,
                          0);
            }
        }
    }
}

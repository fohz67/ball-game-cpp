#include "managers/EntityManager.hpp"

#include <components/Color.hpp>
#include <components/Link.hpp>
#include <components/Position.hpp>
#include <components/Shape.hpp>
#include <components/Sprite.hpp>
#include <components/Text.hpp>
#include <components/Texture.hpp>

#include "System.hpp"
#include "config/ConfigClient.hpp"

EntityManager& EntityManager::get()
{
    static EntityManager instance;
    return instance;
}

const void EntityManager::createCell(const uint32_t id,
                                     const double x,
                                     const double y,
                                     const double radius,
                                     std::vector<double> color,
                                     const std::string& nickname)
{
    if (color.size() != 4)
    {
        color = {255, 255, 255, 255};
    }

    GameEngine::Entity newCell(id);

    newCell.addComponent(Shape(ShapeType::Circle, {radius * 2, radius * 2}, radius));
    newCell.addComponent(Position({{x, y}}));
    newCell.addComponent(Color(color));

    entities.emplace(id, std::move(newCell));

    if (nickname.length() > 0)
    {
        // createNickname(id, x, y, radius, nickname);
    }
}

const void EntityManager::createNickname(const uint32_t id,
                                         const double x,
                                         const double y,
                                         const double radius,
                                         const std::string& nickname)
{
    auto newNickname = GameEngine::Entity(id + ConfigClient::Network::ENTITY_LINKING_BIAS);

    newNickname.addComponent(
        Text(nickname,
             "assets/fonts/" + ConfigClient::Player::Nickname::FONT_FAMILY + "/" +
                 std::to_string(ConfigClient::Player::Nickname::FONT_WEIGHT) + ".ttf",
             ConfigClient::Player::Nickname::TEXT_SIZE));
    newNickname.addComponent(Position({{x + radius, y + radius}}));
    newNickname.addComponent(Link(id));

    auto linkingBias = linkedEntitiesBiases.find(id)->second;

    entities.emplace(id + ConfigClient::Network::ENTITY_LINKING_BIAS * linkingBias,
                     std::move(newNickname));
    linkedEntitiesBiases.emplace(id, linkingBias + 1);
}

const void EntityManager::createWorld(const uint16_t size)
{
    GameEngine::Entity newWorld(ConfigClient::World::ID);
    const std::pair<double, double> position = {0.0f, 0.0f};

    newWorld.addComponent(Shape(ShapeType::Rectangle, {size, size}));
    newWorld.addComponent(Position({position}));
    newWorld.addComponent(Color(ConfigClient::World::BACKGROUND_COLOR));

    entities.emplace(ConfigClient::World::ID, std::move(newWorld));
}

const void EntityManager::updateCell(const uint32_t id,
                                     const double x,
                                     const double y,
                                     const double radius,
                                     const bool isNickname)
{
    if (entities.find(id) == entities.end())
    {
        return;
    }

    auto& entity = entities.at(id);
    auto& positionComp = entity.getComponent<Position>();

    positionComp.setPosition({x, y});

    GameEngine::System system;

    system.update(id, entities, GameEngine::UpdateType::ShapeSize, radius);
}

const void EntityManager::removeEntity(const double id)
{
    if (entities.find(id) != entities.end())
    {
        entities.erase(id);
    }

    if (linkedEntitiesBiases.find(id) != linkedEntitiesBiases.end())
    {
        linkedEntitiesBiases.erase(id);
    }
}

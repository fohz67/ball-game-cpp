#include "components/HUD.hpp"

#include <iostream>

#include "components/Color.hpp"
#include "components/Leaderboard.hpp"
#include "components/Position.hpp"
#include "components/Shape.hpp"
#include "components/Text.hpp"
#include "config/ConfigClient.hpp"
#include "engine/GameClient.hpp"
#include "engine/NetworkClient.hpp"
#include "managers/EntityManager.hpp"
#include "managers/PlayerManagerClient.hpp"
#include "protocol/SendClient.hpp"

HUD& HUD::get()
{
    static HUD instance;
    return instance;
}

const void HUD::create()
{
    createLeaderboard();
    createStats();
    createChatBox();
}

const void HUD::update()
{
    static auto lastUpdate = std::chrono::high_resolution_clock::now();
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastUpdate);

    if (elapsed.count() < 1)
    {
        return;
    }

    lastUpdate = now;

    SendClient::sendPing();

    updateStats();
    updateLeaderboard();
}

const void HUD::createLeaderboard()
{
    // Box
    increaseId();

    auto newEntity = GameEngine::Entity(currentId);
    newEntity.addComponent(
        Shape(ShapeType::Rectangle,
              {ConfigClient::HUD::Leaderboard::WIDTH, ConfigClient::HUD::Leaderboard::HEIGHT}));
    newEntity.addComponent(
        Position({{GameClient::get().getWindowSize().x -
                       (ConfigClient::HUD::Leaderboard::WIDTH + ConfigClient::HUD::PADDING),
                   ConfigClient::HUD::PADDING}}));
    newEntity.addComponent(Color(ConfigClient::HUD::BACKGROUND_COLOR));

    EntityManager::get().hudEntities.emplace(currentId, std::move(newEntity));
    leaderboardEntities.emplace(currentId, std::move(newEntity));

    // Title
    increaseId();

    auto newEntityTitle = GameEngine::Entity(currentId);
    newEntityTitle.addComponent(
        Text(ConfigClient::HUD::Leaderboard::TITLE,
             "assets/fonts/" + ConfigClient::HUD::FONT_FAMILY + "/" +
                 std::to_string(ConfigClient::HUD::Leaderboard::FONT_WEIGHT_LABEL) + ".ttf",
             ConfigClient::HUD::Leaderboard::TITLE_SIZE,
             1));
    newEntityTitle.addComponent(
        Position({{GameClient::get().getWindowSize().x - ConfigClient::HUD::Leaderboard::WIDTH / 2 -
                       ConfigClient::HUD::PADDING,
                   ConfigClient::HUD::PADDING + ConfigClient::HUD::Leaderboard::MARGIN_TOP}}));
    newEntityTitle.addComponent(Color(ConfigClient::HUD::TEXT_COLOR));

    EntityManager::get().hudEntities.emplace(currentId, std::move(newEntityTitle));
    leaderboardEntities.emplace(currentId, std::move(newEntityTitle));

    // Players List
    float yOffset = ConfigClient::HUD::PADDING +
                    ConfigClient::HUD::Leaderboard::MARGIN_BETWEEN_TITLE_AND_CONTENT;
    auto players = PlayerManagerClient::get().players;

    for (const auto& player : players)
    {
        int i = 1;

        increaseId();

        auto newPlayerEntity = GameEngine::Entity(currentId);
        newPlayerEntity.addComponent(
            Text(std::to_string(i) + ". " + player.getNickname(),
                 "assets/fonts/" + ConfigClient::HUD::FONT_FAMILY + "/" +
                     std::to_string(ConfigClient::HUD::Leaderboard::FONT_WEIGHT_VALUE) + ".ttf",
                 ConfigClient::HUD::Leaderboard::CONTENT_SIZE,
                 1));
        newPlayerEntity.addComponent(
            Position({{GameClient::get().getWindowSize().x -
                           ConfigClient::HUD::Leaderboard::WIDTH / 2 - ConfigClient::HUD::PADDING,
                       yOffset}}));
        newPlayerEntity.addComponent(Color(ConfigClient::HUD::TEXT_COLOR));

        EntityManager::get().hudEntities.emplace(currentId, std::move(newPlayerEntity));
        leaderboardEntities.emplace(currentId, std::move(newPlayerEntity));

        yOffset += ConfigClient::HUD::Leaderboard::MARGIN_BETWEEN_LINES;
        i++;
    }
}

const void HUD::createStats()
{
    increaseId();

    // Box
    auto newEntity = GameEngine::Entity(currentId);
    newEntity.addComponent(Shape(
        ShapeType::Rectangle, {ConfigClient::HUD::Stats::WIDTH, ConfigClient::HUD::Stats::HEIGHT}));
    newEntity.addComponent(Position({{ConfigClient::HUD::PADDING, ConfigClient::HUD::PADDING}}));
    newEntity.addComponent(Color(ConfigClient::HUD::BACKGROUND_COLOR));

    EntityManager::get().hudEntities.emplace(currentId, std::move(newEntity));
    statsEntity.emplace(currentId, std::move(newEntity));

    // Titles & Values
    float yOffset = ConfigClient::HUD::PADDING + ConfigClient::HUD::Stats::MARGIN_TOP;
    std::vector<std::string> labels = {"Score:", "Mass:", "Cells:", "Ping:", "FPS:"};

    for (const auto& label : labels)
    {
        increaseId();

        // Label
        auto newLabelEntity = GameEngine::Entity(currentId);
        newLabelEntity.addComponent(
            Text(label,
                 "assets/fonts/" + ConfigClient::HUD::FONT_FAMILY + "/" +
                     std::to_string(ConfigClient::HUD::Stats::FONT_WEIGHT_LABEL) + ".ttf",
                 ConfigClient::HUD::Stats::LABEL_SIZE,
                 0));
        newLabelEntity.addComponent(
            Position({{ConfigClient::HUD::PADDING + ConfigClient::HUD::TEXT_PADDING, yOffset}}));
        newLabelEntity.addComponent(Color(ConfigClient::HUD::TEXT_COLOR));

        EntityManager::get().hudEntities.emplace(currentId, std::move(newLabelEntity));
        statsEntity.emplace(currentId, std::move(newLabelEntity));

        // Value
        increaseId();

        auto newValueEntity = GameEngine::Entity(currentId);
        newValueEntity.addComponent(
            Text("0",
                 "assets/fonts/" + ConfigClient::HUD::FONT_FAMILY + "/" +
                     std::to_string(ConfigClient::HUD::Stats::FONT_WEIGHT_VALUE) + ".ttf",
                 ConfigClient::HUD::Stats::VALUE_SIZE,
                 2));
        newValueEntity.addComponent(
            Position({{ConfigClient::HUD::PADDING + ConfigClient::HUD::Stats::WIDTH -
                           ConfigClient::HUD::TEXT_PADDING * 2.8,
                       yOffset}}));
        newValueEntity.addComponent(Color(ConfigClient::HUD::Stats::VALUE_COLOR));

        EntityManager::get().hudEntities.emplace(currentId, std::move(newValueEntity));
        statsEntity.emplace(currentId, std::move(newValueEntity));

        yOffset += ConfigClient::HUD::Stats::MARGIN_BETWEEN_LINES;
    }
}

const void HUD::createChatBox()
{
    increaseId();

    // Box
    auto newEntity = GameEngine::Entity(currentId);
    newEntity.addComponent(
        Shape(ShapeType::Rectangle,
              {ConfigClient::HUD::ChatBox::WIDTH, ConfigClient::HUD::ChatBox::HEIGHT}));
    newEntity.addComponent(
        Position({{ConfigClient::HUD::PADDING,
                   GameClient::get().getWindowSize().y -
                       (ConfigClient::HUD::ChatBox::HEIGHT + ConfigClient::HUD::PADDING)}}));
    newEntity.addComponent(Color(ConfigClient::HUD::BACKGROUND_COLOR));

    EntityManager::get().hudEntities.emplace(currentId, std::move(newEntity));
    chatBoxEntitites.emplace(currentId, std::move(newEntity));
}

const void HUD::updateLeaderboard()
{
    GameEngine::System system;
    double bias = ConfigClient::World::ID + ConfigClient::Network::ENTITY_LINKING_BIAS * 3;

    const std::vector<std::string> leaderboard = Leaderboard::get().getLeaderboard();

    for (const std::string& nickname : leaderboard)
    {
        system.update(
            bias, EntityManager::get().hudEntities, GameEngine::UpdateType::Text, nickname);

        bias += ConfigClient::Network::ENTITY_LINKING_BIAS;
    }
}

const void HUD::updateStats()
{
    GameEngine::System system;
    double bias = ConfigClient::World::ID +
                  (leaderboardEntities.size() * ConfigClient::Network::ENTITY_LINKING_BIAS);

    bias += ConfigClient::Network::ENTITY_LINKING_BIAS * 3;

    system.update(bias,
                  EntityManager::get().hudEntities,
                  GameEngine::UpdateType::Text,
                  std::to_string(score));

    bias += ConfigClient::Network::ENTITY_LINKING_BIAS * 2;

    system.update(
        bias, EntityManager::get().hudEntities, GameEngine::UpdateType::Text, std::to_string(mass));

    bias += ConfigClient::Network::ENTITY_LINKING_BIAS * 2;

    system.update(bias,
                  EntityManager::get().hudEntities,
                  GameEngine::UpdateType::Text,
                  std::to_string(cellCount));

    bias += ConfigClient::Network::ENTITY_LINKING_BIAS * 2;

    system.update(bias,
                  EntityManager::get().hudEntities,
                  GameEngine::UpdateType::Text,
                  std::to_string(NetworkClient::get().getPing()));

    bias += ConfigClient::Network::ENTITY_LINKING_BIAS * 2;

    system.update(bias,
                  EntityManager::get().hudEntities,
                  GameEngine::UpdateType::Text,
                  std::to_string(GameClient::get().getFPS()));
}

const void HUD::increaseId()
{
    currentId += ConfigClient::Network::ENTITY_LINKING_BIAS;
}

const void HUD::setMass(const uint32_t newMass)
{
    mass = newMass;
}

const void HUD::setScore(const uint32_t newScore)
{
    score = newScore;
}

const void HUD::setCellCount(const uint32_t newCellCount)
{
    cellCount = newCellCount;
}

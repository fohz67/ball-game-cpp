#include "components/HUD.hpp"
#include "components/Color.hpp"
#include "components/Position.hpp"
#include "components/Shape.hpp"
#include "components/Text.hpp"
#include "config/ConfigClient.hpp"
#include "engine/GameClient.hpp"
#include "managers/EntityManager.hpp"
#include "managers/PlayerManagerClient.hpp"

HUD& HUD::get() {
    static HUD instance;
    return instance;
}

void HUD::create() {
    createLeaderboard();
    createStats();
    createChatBox();
}

void HUD::createLeaderboard() {
    // Box
    increaseId();

    auto newEntity = GEngine::Entity(currentId);
    newEntity.addComponent(
        Shape(ShapeType::Rectangle,
              {ConfigClient::HUD::Leaderboard::WIDTH, ConfigClient::HUD::Leaderboard::HEIGHT}));
    newEntity.addComponent(
        Position({{GameClient::get().getWindowSize().x -
                       (ConfigClient::HUD::Leaderboard::WIDTH + ConfigClient::HUD::PADDING),
                   ConfigClient::HUD::PADDING}}));
    newEntity.addComponent(Color(ConfigClient::HUD::BACKGROUND_COLOR));

    EntityManager::get().entities.emplace(currentId, std::move(newEntity));
    leaderboardEntities.emplace(currentId, std::move(newEntity));

    // Title
    increaseId();

    auto newEntityTitle = GEngine::Entity(currentId);
    newEntityTitle.addComponent(Text(ConfigClient::HUD::Leaderboard::TITLE,
                                     "assets/fonts/" + ConfigClient::HUD::FONT_FAMILY + "/" +
                                         std::to_string(ConfigClient::HUD::FONT_WEIGHT) + ".ttf",
                                     ConfigClient::HUD::Leaderboard::TITLE_SIZE,
                                     1));
    newEntityTitle.addComponent(
        Position({{GameClient::get().getWindowSize().x - ConfigClient::HUD::Leaderboard::WIDTH / 2 -
                       ConfigClient::HUD::PADDING,
                   ConfigClient::HUD::PADDING + 40}}));
    newEntityTitle.addComponent(Color(ConfigClient::HUD::TEXT_COLOR));

    EntityManager::get().entities.emplace(currentId, std::move(newEntityTitle));
    leaderboardEntities.emplace(currentId, std::move(newEntityTitle));

    // Players List
    float yOffset = ConfigClient::HUD::PADDING + 85;
    auto  players = PlayerManagerClient::get().players;

    for (const auto& player : players) {
        int i = 1;

        increaseId();

        auto newPlayerEntity = GEngine::Entity(currentId);
        newPlayerEntity.addComponent(Text(std::to_string(i) + ". " + player.getNickname(),
                                          "assets/fonts/" + ConfigClient::HUD::FONT_FAMILY + "/" +
                                              std::to_string(ConfigClient::HUD::FONT_WEIGHT) +
                                              ".ttf",
                                          ConfigClient::HUD::Leaderboard::CONTENT_SIZE,
                                          1));
        newPlayerEntity.addComponent(
            Position({{GameClient::get().getWindowSize().x -
                           ConfigClient::HUD::Leaderboard::WIDTH / 2 - ConfigClient::HUD::PADDING,
                       yOffset}}));
        newPlayerEntity.addComponent(Color(ConfigClient::HUD::TEXT_COLOR));

        EntityManager::get().entities.emplace(currentId, std::move(newPlayerEntity));
        leaderboardEntities.emplace(currentId, std::move(newPlayerEntity));

        yOffset += 50;
        i++;
    }
}

void HUD::createStats() {
    increaseId();

    // Box
    auto newEntity = GEngine::Entity(currentId);
    newEntity.addComponent(Shape(
        ShapeType::Rectangle, {ConfigClient::HUD::Stats::WIDTH, ConfigClient::HUD::Stats::HEIGHT}));
    newEntity.addComponent(Position({{ConfigClient::HUD::PADDING, ConfigClient::HUD::PADDING}}));
    newEntity.addComponent(Color(ConfigClient::HUD::BACKGROUND_COLOR));

    EntityManager::get().entities.emplace(currentId, std::move(newEntity));
    statsEntity.emplace(currentId, std::move(newEntity));

    // Titles & Values
    float                    yOffset = ConfigClient::HUD::PADDING + 30;
    std::vector<std::string> labels  = {"Score:", "Mass:", "Ping:", "FPS:"};

    for (const auto& label : labels) {
        increaseId();

        // Label
        auto newLabelEntity = GEngine::Entity(currentId);
        newLabelEntity.addComponent(Text(label,
                                         "assets/fonts/" + ConfigClient::HUD::FONT_FAMILY + "/" +
                                             std::to_string(ConfigClient::HUD::FONT_WEIGHT) +
                                             ".ttf",
                                         ConfigClient::HUD::Stats::LABEL_SIZE,
                                         0));
        newLabelEntity.addComponent(
            Position({{ConfigClient::HUD::PADDING + ConfigClient::HUD::TEXT_PADDING, yOffset}}));
        newLabelEntity.addComponent(Color(ConfigClient::HUD::TEXT_COLOR));

        EntityManager::get().entities.emplace(currentId, std::move(newLabelEntity));
        statsEntity.emplace(currentId, std::move(newLabelEntity));

        // Value
        increaseId();

        auto newValueEntity = GEngine::Entity(currentId);
        newValueEntity.addComponent(Text("0",
                                         "assets/fonts/" + ConfigClient::HUD::FONT_FAMILY + "/" +
                                             std::to_string(ConfigClient::HUD::FONT_WEIGHT) +
                                             ".ttf",
                                         ConfigClient::HUD::Stats::VALUE_SIZE,
                                         2));
        newValueEntity.addComponent(
            Position({{ConfigClient::HUD::PADDING + ConfigClient::HUD::Stats::WIDTH -
                           ConfigClient::HUD::TEXT_PADDING,
                       yOffset}}));
        newValueEntity.addComponent(Color(ConfigClient::HUD::Stats::VALUE_COLOR));

        EntityManager::get().entities.emplace(currentId, std::move(newValueEntity));
        statsEntity.emplace(currentId, std::move(newValueEntity));

        yOffset += 40;
    }
}

void HUD::createChatBox() {
    increaseId();

    // Box
    auto newEntity = GEngine::Entity(currentId);
    newEntity.addComponent(
        Shape(ShapeType::Rectangle,
              {ConfigClient::HUD::ChatBox::WIDTH, ConfigClient::HUD::ChatBox::HEIGHT}));
    newEntity.addComponent(
        Position({{ConfigClient::HUD::PADDING,
                   GameClient::get().getWindowSize().y -
                       (ConfigClient::HUD::ChatBox::HEIGHT + ConfigClient::HUD::PADDING)}}));
    newEntity.addComponent(Color(ConfigClient::HUD::BACKGROUND_COLOR));

    EntityManager::get().entities.emplace(currentId, std::move(newEntity));
    chatBoxEntitites.emplace(currentId, std::move(newEntity));
}

void HUD::increaseId() {
    currentId += ConfigClient::Network::ENTITY_LINKING_BIAS;
}

void HUD::setMass(long newMass) {}

void HUD::setScore(long newScore) {}
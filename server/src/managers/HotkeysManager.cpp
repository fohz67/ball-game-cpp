#include "managers/HotkeysManager.hpp"
#include "config/Config.hpp"
#include "managers/CellManager.hpp"
#include "managers/PlayerManager.hpp"

HotkeysManager& HotkeysManager::get() {
    static HotkeysManager instance;
    return instance;
}

void HotkeysManager::handleKeyPressed(
    std::shared_ptr<asio::ip::tcp::socket> client, const std::string& keyName) {
    if (keyName == "SPACE") {
        CellManager::get().splitCells(
            *PlayerManager::get().getPlayerByClient(client));
    }
}

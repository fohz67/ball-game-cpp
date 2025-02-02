#pragma once

#include <asio.hpp>

class HotkeysManager {
  public:
    HotkeysManager(const HotkeysManager&) = delete;
    HotkeysManager& operator=(const HotkeysManager&) = delete;

    static HotkeysManager& get();

    void handleKeyPressed(std::shared_ptr<asio::ip::tcp::socket> client,
                          const std::string& keyName);

  private:
    HotkeysManager() = default;
    ~HotkeysManager() = default;
};

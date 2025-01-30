#pragma once

#include <iostream>
#include "Network.hpp"
#include "OpCodes.hpp"
#include "SmartBuffer.hpp"

class Protocol {
  public:
    static void injector(char* buffer, size_t length, SmartBuffer& smartBuffer);
    static void handle_message(Network& network,
                               std::shared_ptr<asio::ip::tcp::socket> client,
                               SmartBuffer& smartBuffer);
};

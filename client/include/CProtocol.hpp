#pragma once

#include <SmartBuffer.hpp>
#include <iostream>

class CProtocol {
  public:
    static void injector(char* buffer, size_t length, SmartBuffer& smartBuffer);
    static void handle_message(SmartBuffer& smartBuffer);
};

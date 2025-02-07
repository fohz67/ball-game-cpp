#pragma once

#include <SmartBuffer.hpp>

class ProtocolClient
{
   public:
    ProtocolClient(const ProtocolClient&) = delete;
    ProtocolClient& operator=(const ProtocolClient&) = delete;

    static ProtocolClient& get();

    const void handleMessage(SmartBuffer& smartBuffer);

   private:
    ProtocolClient() = default;
    ~ProtocolClient() = default;
};

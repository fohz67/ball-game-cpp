---
title: Client Network
slug: /client/network
---

# Client Network

The **Client Network** module is responsible for handling all network communication between the game client and the server. It manages sending and receiving packets, handling protocol messages, and maintaining a stable connection.

## Overview
The network system of the client uses **Asio** for asynchronous communication, allowing efficient message handling without blocking the main game loop.

### Key Responsibilities:
- Establishing a connection to the server.
- Sending data packets using the defined protocol.
- Receiving and processing messages asynchronously.
- Managing connection stability and error handling.
- Synchronizing the game state with the server.

---

## Connection Handling
The client connects to the server by resolving the provided hostname and port. The `NetworkClient` class manages the connection lifecycle.

### Initialization
```cpp
asio::ip::tcp::resolver resolver(io_context);
asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(host, std::to_string(port));
asio::connect(socket, endpoints);
```
- Resolves the server’s hostname and establishes a connection.
- Uses Asio’s `connect` function to bind the socket to the server.
- Once connected, the **network thread** is started for continuous message handling.

### Network Thread
A dedicated thread listens for incoming packets:
```cpp
networkThread = std::thread(&NetworkClient::receive, this);
```
- Ensures non-blocking network operations.
- Listens for messages from the server.
- Forwards data to the protocol handler for processing.

---

## Sending Data
Messages are sent using the **SmartBuffer** system, ensuring efficient serialization.

### Sending a Message
```cpp
SmartBuffer smartBuffer;
smartBuffer << OpCodes::PINGPONG;
NetworkClient::get().send(smartBuffer);
```
- Constructs a packet with an **OpCode**.
- Serializes it into a `SmartBuffer`.
- Sends it over the socket.

### Sending Mouse Position
```cpp
const sf::Vector2i mousePos = sf::Mouse::getPosition(window);
const sf::Vector2u windowSize = window.getSize();
SmartBuffer smartBuffer;
smartBuffer << OpCodes::UPDATE_MOUSE_POSITION << normalizedX << normalizedY;
NetworkClient::get().send(smartBuffer);
```
- Captures the mouse position relative to the screen.
- Normalizes values between -1 and 1.
- Sends the data to the server for movement updates.

---

## Receiving Data
Data is received asynchronously and handled in **ProtocolClient**.

### Receiving a Packet
```cpp
uint32_t packetSize;
asio::read(socket, asio::buffer(&packetSize, sizeof(packetSize)));
std::vector<uint8_t> buffer(packetSize);
asio::read(socket, asio::buffer(buffer.data(), packetSize));
```
- Reads the **packet size** first.
- Allocates memory based on the expected size.
- Reads the full message into a buffer.

### Handling Messages
```cpp
uint8_t opcode;
smartBuffer >> opcode;
switch (static_cast<OpCodes>(opcode))
{
    case OpCodes::CREATE_WORLD:
        ReadClient::readCreateWorld(smartBuffer);
        break;
    case OpCodes::UPDATE_PLAYER:
        ReadClient::readUpdatePlayer(smartBuffer);
        break;
}
```
- Extracts the **OpCode** from the packet.
- Routes the message to the appropriate handler in **ReadClient**.

---

## Synchronization with Server
The client continuously syncs its game state with the server.
- **Game entities are updated** based on received messages.
- **Leaderboard updates** reflect real-time score changes.
- **Mouse input** is sent in real-time for smooth movement.

---

## Error Handling
If an error occurs during connection or data transfer, the client logs the issue and attempts to recover:
```cpp
catch (const std::exception& e)
{
    std::cerr << "Network error: " << e.what() << std::endl;
    exit(0);
}
```
- If a critical failure occurs, the client terminates safely.
- In case of connection loss, the client may attempt to reconnect (future implementation).

---

## Summary
The client network module efficiently manages communication with the server using Asio. It ensures a **smooth gameplay experience** by handling network messages asynchronously, reducing latency, and keeping game entities synchronized with the server state.

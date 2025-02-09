---
title: Network
slug: /server/network
---

This document provides an overview of the **network architecture** used in the Ball Game project. It explains the **TCP-based communication**, **packet structure**, **message handling**, **protocol design**, and the use of **ASIO** for networking.

---

## Overview

The networking system is responsible for **handling client connections, sending and receiving packets, and processing game state updates.** It is built on **ASIO (Boost.Asio)** for efficient asynchronous I/O operations and uses **TCP** for reliable data transmission.

The system consists of:
- A **network thread** running asynchronously to handle incoming and outgoing messages.
- **Clients allocation** and management.
- A **packet system** with structured messages and a defined **protocol**.
- **Serialization** and **deserialization** using `SmartBuffer`.

---

## TCP Communication Model

### Why TCP?
The game uses **TCP** (Transmission Control Protocol) instead of **UDP** for network communication due to:
- **Reliability**: TCP ensures all packets arrive **in order** and **without loss**.
- **Built-in congestion control**: Prevents overwhelming the network.
- **Persistent connection**: Ideal for **real-time state synchronization**.

### Connection Lifecycle
1. **Client requests a connection** to the server.
2. The **server accepts the connection** and assigns a **socket**.
3. The **server and client exchange packets** via **TCP streams**.
4. If the client disconnects, the **server cleans up resources**.

---

## Packet Structure

Each packet follows a structured format:

| Field       | Type      | Size (bytes) | Description                               |
|------------|-----------|-------------|-------------------------------------------|
| **Size**   | `uint32_t` | 4           | Size of the full packet (excluding this field). |
| **OpCode** | `uint8_t`  | 1           | Identifies the type of packet.           |
| **Payload**| Varies     | Variable    | The actual packet data.                   |

The **size field (uint32_t)** at the start of each packet allows the receiver to determine the **full size** of the incoming data. This helps in handling **packet fragmentation**.

### Handling Cut Packets (Packet Fragmentation)

Since **TCP is a stream-based protocol**, it does **not guarantee** that a full packet is received in a single read operation. To handle this, we use:

- **A size field (`uint32_t`)** at the start of every packet.
- The **receiver first reads 4 bytes** to determine the **expected packet size**.
- The receiver then **buffers incoming data** until the full packet is received.

This ensures that **even if a message is split across multiple TCP segments,** it is correctly reconstructed.

---

## Protocol Design

The **network protocol** defines how **messages** are structured and exchanged between the server and clients.

### OpCodes (Message Types)
Each packet has an **OpCode** (`uint8_t`) that determines its **purpose**. Example OpCodes:
- `PINGPONG` (0) – Used for latency measurement.
- `JOIN_SERVER` (10) – Sent when a player connects.
- `CREATE_PLAYER` (20) – Sent when a new player is created.
- `UPDATE_GAME_STATE` (40) – Sends game state updates.
- `DELETE_ENTITY` (50) – Notifies the removal of an entity.

### Serialization with `SmartBuffer`
The protocol uses a **binary format** for efficiency. `SmartBuffer` handles **serialization (writing)** and **deserialization (reading)** of data.

Example:
- **Writing a packet:** `smartBuffer << OpCodes::CREATE_PLAYER << playerId << playerName;`
- **Reading a packet:** `smartBuffer >> opcode >> playerId >> playerName;`

This makes **encoding and decoding packets efficient and flexible**.

---

## Network Thread

The **network operates on a separate thread** to ensure smooth handling of **incoming and outgoing messages** without blocking the main game loop.

### Main Responsibilities:
- **Accepting new connections.**
- **Reading packets asynchronously.**
- **Sending packets efficiently.**
- **Managing clients and their sockets.**
- **Handling disconnections.**

### How It Works:
1. **`asyncAccept()`** – Listens for incoming client connections.
2. **`asyncRead(socket)`** – Reads data from the client.
3. **`handleMessage(socket, buffer)`** – Parses the received packet.
4. **`sendToClient(socket, buffer)`** – Sends data to a specific client.
5. **`sendToAll(buffer)`** – Broadcasts data to all clients.

---

## ASIO and Asynchronous Operations

The **networking system** is built on **ASIO** for **asynchronous, non-blocking I/O**. This allows the server to handle **multiple connections** efficiently.

### Key Features of ASIO:
- **`asio::ip::tcp::socket`**: Represents a connection with a client.
- **`asio::ip::tcp::acceptor`**: Listens for incoming connections.
- **`async_read_some()`**: Reads data asynchronously.
- **`async_write()`**: Sends data without blocking.

ASIO ensures that the server **remains responsive** while handling multiple clients.

---

## Sending and Receiving Messages

### Sending Data:
1. **Create a `SmartBuffer` instance.**
2. **Write the OpCode and payload.**
3. **Send using `sendToClient()` or `sendToAll()`.**

Example:
```cpp
SmartBuffer smartBuffer;
smartBuffer << OpCodes::CREATE_PLAYER << playerId << playerName;
Network::get().sendToClient(client, smartBuffer);
```

### Receiving Data:
1. **Read the first 4 bytes** (packet size).
2. **Wait until the full packet is received.**
3. **Extract the OpCode.**
4. **Process the message based on its OpCode.**

Example:
```cpp
uint8_t opcode;
smartBuffer >> opcode;

switch (static_cast<OpCodes>(opcode)) {
    case OpCodes::PINGPONG:
        handlePingPong(client, smartBuffer);
        break;
    case OpCodes::JOIN_SERVER:
        handleJoinServer(client, smartBuffer);
        break;
    default:
        std::cout << "Unknown OpCode received!" << std::endl;
}
```

---

## Client Allocation and Management

The **server maintains a list of connected clients** and their associated sockets.

- **New clients** are stored in a `std::map`.
- **Each client has a unique ID** generated by `AtomicID`.
- **Disconnected clients are removed** from the list and their ID is recycled.

### Handling Disconnections
If a client disconnects:
1. The **socket is closed**.
2. The **player ID is freed** using `AtomicID::removeId()`.
3. The **player’s data is removed** from the game state.

---

## Summary

- **Uses TCP** for **reliable and ordered data transmission**.
- **Handles packet fragmentation** using a **size-prefixed message format**.
- **Manages network operations asynchronously** with **ASIO**.
- **Separates networking from gameplay logic** with a dedicated **network thread**.
- **Uses an OpCode-based protocol** for structured messaging.
- **Supports client allocation, disconnection handling, and efficient data sending.**

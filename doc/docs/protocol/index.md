---
title: Protocol
slug: /protocol
---

# Ball Game Protocol Documentation

This document provides an overview of the communication protocol for the Ball Game server. It defines the purpose, payload, and transmission method for each operation code (OpCode).

## Message Structure
All messages follow a structured format:

| Field       | Type      | Size (bytes) | Description                               |
|------------|----------|--------------|-------------------------------------------|
| **OpCode**  | `uint8_t` | 1            | Identifies the operation (see below).     |
| **Payload** | Varies    | Variable     | Data relevant to the specific operation.  |

Each message begins with an **OpCode**, followed by a **payload** containing relevant data.

---

## OpCode Definitions

### 0. **PINGPONG**
- **Value**: `0`
- **Description**: Used to test the connection between the client and the server.
- **Payload**:
  - `timestamp` (uint64_t): The timestamp when the packet is sent.
- **Sent To**: Server.
- **Send From**: Client.

### 1. **CREATE_WORLD**
- **Value**: `1`
- **Description**: Sends the game world configuration to the client.
- **Payload**:
  - `size` (uint16_t): The world size.
- **Sent To**: Client.

### 10. **JOIN_SERVER**
- **Value**: `10`
- **Description**: Sent when a player joins the game.
- **Payload**: None.
- **Sent To**: Server.

### 20. **CREATE_PLAYER**
- **Value**: `20`
- **Description**: Sends new player data to all clients.
- **Payload**:
  - `id` (uint32_t): ID of the player.
  - `color` (uint32_t): Color of the nickname.
  - `cellColor` (uint32_t): Color of the cells.
- **Sent To**: All clients.

### 21. **UPDATE_PLAYER**
- **Value**: `21`
- **Description**: Sends viewport updates to clients.
- **Payload**:
  - `x` (double): Viewport X position.
  - `y` (double): Viewport Y position.
- **Sent To**: Client.

### 22. **DELETE_PLAYER**
- **Value**: `22`
- **Description**: Notifies all clients that a player has been removed.
- **Payload**:
  - `playerId` (uint32_t): ID of the deleted player.
- **Sent To**: All clients.

### 30. **SPAWN_PELLETS**
- **Value**: `30`
- **Description**: Sends all pellet data to the client.
- **Payload**:
  - `id` (uint32_t): ID of the pellet.
  - `x` (double): X position.
  - `y` (double): Y position.
  - `radius` (double): Radius of the pellet.
  - `color` (uint32_t): Color of the pellet.
- **Sent To**: Client.

### 31. **SPAWN_PELLET**
- **Value**: `31`
- **Description**: Sends a single pellet spawn event.
- **Payload**:
  - `id` (uint32_t): ID of the pellet.
  - `x` (double): X position.
  - `y` (double): Y position.
  - `radius` (double): Radius of the pellet.
  - `color` (uint32_t): Color of the pellet.
- **Sent To**: All clients.

### 40. **UPDATE_GAME_STATE**
- **Value**: `40`
- **Description**: Sends all cells' updates to clients.
- **Payload**:
  - `ownerId` (uint32_t): ID of the owner.
  - `id` (uint32_t): ID of the cell.
  - `x` (double): X position.
  - `y` (double): Y position.
  - `radius` (double): Radius of the cell.
- **Sent To**: All clients.

### 41. **UPDATE_LEADERBOARD**
- **Value**: `41`
- **Description**: Sends leaderboard updates to all clients.
- **Payload**:
  - `leaderboard` (vector string): List of top players.
- **Sent To**: All clients.

### 50. **DELETE_ENTITY**
- **Value**: `50`
- **Description**: Notifies all clients that an entity has been removed.
- **Payload**:
  - `entityType` (uint8_t): Type of entity (0 = player, others = non-player entities).
  - `entityId` (uint32_t): ID of the deleted entity.
- **Sent To**: All clients.

### 60. **UPDATE_MOUSE_POSITION**
- **Value**: `60`
- **Description**: Sends the player's mouse position to the server.
- **Payload**:
  - `normX` (double): Normalized X coordinate.
  - `normY` (double): Normalized Y coordinate.
- **Sent To**: Server.

---

## Notes
- The `SmartBuffer` ensures efficient serialization and deserialization of messages.
- Players' states are updated asynchronously to minimize latency.
- `Protocol` handles routing and parsing of messages between the server and clients.


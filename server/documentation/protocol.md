# R-Type Protocol Documentation

This document provides an overview of the communication protocol for the Ball Game server. It defines the purpose, payload, and transmission method for each operation code (OpCode).

---

## Message Structure
All messages follow a structured format:

| Field       | Type      | Size (bytes) | Description                               |
|-------------|-----------|--------------|-------------------------------------------|
| **OpCode**  | `uint8_t` | 1            | Identifies the operation (see below).     |
| **Payload** | Varies    | Variable     | Data relevant to the specific operation.  |

Each message begins with an **OpCode**, followed by a **payload** containing relevant data.

---

## OpCode Definitions

### 1. **WORLD**
- **Value**: `1`
- **Description**: Sends the game world configuration to the client.
- **Payload**:
  - `size` (uint16_t): The world size.
- **Sent To**: Client.

### 2. **JOIN**
- **Value**: `2`
- **Description**: Sent when a player joins the game.
- **Payload**: None.
- **Sent To**: Server.

### 3. **GAME_STATE**
- **Value**: `3`
- **Description**: Sends the current game state.
- **Payload**:
  - `ownerId` (uint32_t): ID of the owner.
  - `id` (uint32_t): ID of the cell.
  - `x` (double): X position.
  - `y` (double): Y position.
  - `radius` (double): Radius of the entity.
  - `color` (uint32_t): Color of the cell.
- **Sent To**: All clients.

### 4. **VIEWPORT**
- **Value**: `4`
- **Description**: Sends viewport updates to clients.
- **Payload**:
  - `x` (double): Viewport X position.
  - `y` (double): Viewport Y position.
- **Sent To**: Client.

### 5. **MOUSE_POSITION**
- **Value**: `5`
- **Description**: Sends the player's mouse position.
- **Payload**:
  - `normX` (double): Normalized X coordinate.
  - `normY` (double): Normalized Y coordinate.
- **Sent To**: Server.

### 6. **KEY_PRESSED**
- **Value**: `6`
- **Description**: Notifies the server of a key press.
- **Payload**:
  - `keyName` (string): The key pressed.
- **Sent To**: Server.

---

## Notes
- The `SmartBuffer` ensures efficient serialization and deserialization of messages.
- Players' states are updated asynchronously to minimize latency.
- `Protocol` handles routing and parsing of messages between server and clients.


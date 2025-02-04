# Ball Game Protocol Documentation

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

### 0. **PINGPONG**
- **Value**: `0`
- **Description**: Sends the game world configuration to the client.
- **Payload**:
  - `timestamp` (uint64_t): The timestamp when the packet is sent to the server.
- **Sent To**: Server.
- **Send From**: Server.

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

### 3. **PLAYER**
- **Value**: `3`
- **Description**: Sends new player.
- **Payload**:
  - `id` (uint32_t): ID of the player.
  - `color` (uint32_t): Color of the nickname.
  - `cellColor` (uint32_t): Color of the cells.
- **Sent To**: All clients.

### 4. **CELL**
- **Value**: `4`
- **Description**: Sends all cells.
- **Payload**:
  - `ownerId` (uint32_t): ID of the owner.
  - `id` (uint32_t): ID of the cell.
  - `x` (double): X position.
  - `y` (double): Y position.
  - `radius` (double): Radius of the cell.
- **Sent To**: All clients.

### 5. **PELLET**
- **Value**: `5`
- **Description**: Sends all pellets.
- **Payload**:
  - `id` (uint32_t): ID of the cell.
  - `x` (double): X position.
  - `y` (double): Y position.
  - `radius` (double): Radius of the pellet.
  - `color` (uint32_t): Color of the pellet.
- **Sent To**: Client.

### 6 **VIEWPORT**
- **Value**: `6`
- **Description**: Sends viewport updates to clients.
- **Payload**:
  - `x` (double): Viewport X position.
  - `y` (double): Viewport Y position.
- **Sent To**: Client.

### 7. **MOUSE_POSITION**
- **Value**: `7`
- **Description**: Sends the player's mouse position.
- **Payload**:
  - `normX` (double): Normalized X coordinate.
  - `normY` (double): Normalized Y coordinate.
- **Sent To**: Server.

### 8. **KEY_PRESSED**
- **Value**: `8`
- **Description**: Notifies the server of a key press.
- **Payload**:
  - `keyName` (string): The key pressed.
- **Sent To**: Server.

### 9. **ENTITY_REMOVED**
- **Value**: `9`
- **Description**: Notifies all clients that an entity has been removed
- **Payload**:
  - `entityType` (uint8_t): Player or not (0 = player, otherwise, it's not).
  - `entityId` (uint32_t): ID of the entity.
- **Sent To**: All clients.

---

## Notes
- The `SmartBuffer` ensures efficient serialization and deserialization of messages.
- Players' states are updated asynchronously to minimize latency.
- `Protocol` handles routing and parsing of messages between server and clients.


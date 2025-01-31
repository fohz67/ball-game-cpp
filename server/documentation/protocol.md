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
  - `x` (double): X position.
  - `y` (double): Y position.
  - `radius` (double): Radius of the entity.
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

## Protocol Implementation

### Server
```cpp
void Protocol::handleMessage(std::shared_ptr<asio::ip::tcp::socket> client, SmartBuffer& smartBuffer) {
    uint8_t opcode;
    smartBuffer >> opcode;
    
    switch (static_cast<OpCodes>(opcode)) {
        case OpCodes::JOIN:
            handleJoin(client, smartBuffer);
            break;
        case OpCodes::MOUSE_POSITION:
            handleMousePosition(client, smartBuffer);
            break;
        // etc...
        default:
            std::cout << "Unknown opcode received: " << static_cast<int>(opcode) << std::endl;
            break;
    }
}
```

### Client
```cpp
void ProtocolClient::handleMessage(SmartBuffer& smartBuffer) {
    uint8_t opcode;
    smartBuffer >> opcode;
    
    switch (static_cast<OpCodes>(opcode)) {
        case OpCodes::WORLD:
            handleWorld(smartBuffer);
            break;
        case OpCodes::GAME_STATE:
            handleGameState(smartBuffer);
            break;
        // etc....
        default:
            std::cout << "Unknown opcode received: " << static_cast<int>(opcode) << std::endl;
            break;
    }
}
```

---

## Notes
- The `SmartBuffer` ensures efficient serialization and deserialization of messages.
- Players' states are updated asynchronously to minimize latency.
- `Protocol` handles routing and parsing of messages between server and clients.


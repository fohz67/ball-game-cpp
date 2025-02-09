---
title: Optimizations
slug: /server/optimizations
---

This document provides an in-depth explanation of how memory management, threading, object pooling, and performance optimizations are handled in the game server.

---

## Memory Management

The server ensures efficient memory usage by:

- **AtomicID Management:**
  - The `AtomicID` system generates unique identifiers for game entities while allowing efficient ID reuse. When an entity is deleted, its ID is pushed onto a `recycledIds` stack to be reused instead of creating new IDs unnecessarily.
  
- **SmartBuffer Serialization:**
  - The `SmartBuffer` class handles message serialization, reducing memory fragmentation and ensuring efficient data packing when sending network packets.

- **Object Lifetime Management:**
  - Entities such as players and cells are stored in STL containers (`std::vector`, `std::unordered_map`).
  - Players are managed via `PlayerManager`, while cells and pellets are managed in `CellManager`.
  - Players and entities are dynamically allocated and freed efficiently to avoid memory leaks.

- **Memory Cleanup:**
  - Objects (players, cells, pellets) are explicitly removed using `removePlayer()` and `deleteCells()` when they are no longer needed.
  - The server ensures that `AtomicID::removeId()` is called to mark an ID for reuse.

---

## Threading Model

The server utilizes multi-threading for performance, preventing blocking operations from degrading game performance. The main components of the threading model include:

- **Main Game Thread**:
  - The core simulation loop runs in a separate thread (`Game::updateThread`), handling physics updates, leaderboard calculations, and bot AI.

- **Network Thread**:
  - The ASIO networking library (`Network::run()`) runs in its own thread, handling TCP client connections asynchronously.
  - `asyncRead()` listens for incoming packets and processes them without blocking.
  - The `sendLoop()` thread sends update messages to all clients at a fixed rate.

- **Game Logic Thread**:
  - The `updateLoop()` thread manages game state updates, including movement, decay, and interactions.

- **Worker Thread for AI Bots**:
  - Bot behavior (`AI::computeAIMovement()`) is calculated in the main game loop without blocking other operations.

---

## Object Pooling and Optimizations

The game server implements various optimizations to ensure high performance and scalability:

### **1. Object Pooling**
- Instead of continuously allocating and deallocating game objects, objects are recycled.
- The `AtomicID` system allows ID reuse to prevent excessive allocation.
- `CellManager` maintains an active list of cells and reuses pellet IDs when they are deleted.

### **2. Packet Batching**
- The `SmartBuffer` ensures that multiple game updates are combined into fewer packets to reduce network overhead.
- The server prevents exceeding `Config::Network::MAX_SIZE` by flushing packets before they exceed the limit.

### **3. Reduced Redundant Updates**
- Leaderboard updates and other infrequent state changes are only sent when necessary (`Send::sendUpdateLeaderboard()`).
- Pellets are respawned in batches instead of one-by-one for better efficiency.

### **4. Efficient Collision Handling**
- Instead of checking every cell against every other cell (`O(n^2)` complexity), cell updates are done in a structured order, avoiding redundant calculations.
- `Eat::RESOLVE_FACTOR` prevents excessive collision resolution calls.

### **5. AI Performance Considerations**
- Bot movement calculations occur every update but prioritize larger threats and targets to reduce unnecessary checks.
- AI decisions are cached and updated at controlled intervals to prevent excess CPU usage.

---

## Summary
- The server uses **multi-threading** to handle network, game logic, and AI separately.
- **Memory-efficient ID reuse** via `AtomicID` prevents excessive allocation/deallocation.
- **Object pooling** optimizes pellets and cells, preventing frequent new allocations.
- **SmartBuffer optimizes network traffic** by batching messages efficiently.
- **Physics and AI are optimized** to ensure smooth gameplay at scale.

These techniques ensure that the game server remains scalable, performant, and responsive, even with multiple concurrent players.

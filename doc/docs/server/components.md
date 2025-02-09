---
title: Components
slug: /server/components
---

## Overview
This document provides an in-depth explanation of the core game components, including **Cell**, **Player**, **World**, and other essential elements. These components define the game's mechanics, interactions, and overall simulation.

---

## 1. **World Component**

### Purpose
The **World** component represents the game space where all entities exist. It defines the world size, boundaries, and rules that apply to objects inside it.

### Attributes
- **Size**: Defined by `Config::Gameplay::World::SIZE`, determining the playable area.
- **Boundaries**: The world has fixed edges to keep entities within a defined space.

### Responsibilities
- Defines the **playable area**.
- Provides **boundaries** for movement and component interactions.
- Ensures no component moves **out of bounds**.

---

## 2. **Player Component**

### Purpose
The **Player** component represents an individual user or bot controlling a set of cells. Each player has a unique ID and attributes defining their gameplay experience.

### Attributes
- **ID**: Unique identifier (`uint32_t`).
- **Nickname**: Display name of the player.
- **Color**: Player's assigned color.
- **CellColor**: Color of the player's cells.
- **Viewport**: Camera position centered on the player's controlled area.
- **Mouse Position**: Last known normalized mouse coordinates.
- **Score**: Current game score based on cell mass.
- **Total Mass**: Sum of all controlled cells.
- **Cell Count**: Number of active cells.
- **IsBot**: Boolean flag indicating if the player is an AI bot.

### Responsibilities
- Maintains **player state**.
- Tracks **viewport** (camera movement based on player movement).
- Stores **player's controlled cells**.
- Determines **player statistics** (mass, score, etc.).

### Player Behavior
- **Real Players**: Have an associated network client (`asio::ip::tcp::socket`).
- **Bots**: Controlled by AI and have movement logic (`AI::computeAIMovement()`).

---

## 3. **Cell Component**

### Purpose
The **Cell** component represents the fundamental game component that players control. Cells can grow, shrink, move, and consume other cells or pellets.

### Attributes
- **ID**: Unique identifier (`uint32_t`).
- **Owner ID**: Links the cell to its controlling player.
- **Type**: `PLAYER` or `PELLET`.
- **Position**: Current location in the world.
- **Mass**: Determines the size and movement speed.
- **Radius**: Calculated dynamically based on mass.
- **Color**: Cell appearance.
- **Marked for Deletion**: Flag to indicate if a cell is scheduled for removal.

### Responsibilities
- Handles **movement** based on player input.
- Manages **growth** when consuming pellets or other cells.
- Implements **collision detection** and **cell merging**.
- Tracks **decay over time** to prevent infinite growth.
- Ensures **cells remain within world boundaries**.

### Behavior
- **Movement**: Controlled via player input or AI logic.
- **Eating Other Cells**: A cell can absorb another if it's significantly larger.
- **Decay**: Over time, cells slowly lose mass to balance gameplay.

---

## 4. **Pellet Component**

### Purpose
Pellets are static food sources that provide mass when eaten by a player-controlled cell.

### Attributes
- **ID**: Unique identifier.
- **Position**: Randomly placed in the world.
- **Mass**: Fixed and small.
- **Color**: Assigned randomly.

### Responsibilities
- Spawns randomly in the world.
- Gets removed when eaten.
- Replenishes over time.

---

## 5. **Leaderboard Component**

### Purpose
The **Leaderboard** tracks the top players based on total mass and score.

### Attributes
- **Entries**: A list of the highest-ranked players.
- **Max Entries**: Limits the number of displayed players.

### Responsibilities
- Collects **player data**.
- Sorts players based on **total mass**.
- Sends updates to clients via **`Send::sendUpdateLeaderboard()`**.

---

## 6. **AI Component (Bot Logic)**

### Purpose
The AI system controls bot players, making them interact with the game world automatically.

### Behavior
- **Chasing**: Moves toward smaller entities to consume them.
- **Avoiding**: Runs away from larger entities.
- **Wandering**: Moves randomly when no threat or food is nearby.
- **Pellet Hunting**: Prioritizes small food sources when no players are nearby.

---

## Summary
These components together define the **gameplay structure**. The **World** sets boundaries, **Players** control cells, **Cells** grow and interact, **Pellets** provide resources, and the **Leaderboard** tracks progress. AI ensures dynamic behavior, making the game world feel **alive**.

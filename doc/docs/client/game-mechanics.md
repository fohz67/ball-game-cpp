---
title: Game Mechanics
slug: /client/game-mechanics
---

# Game Mechanics (Client-Side)

This document explains the game mechanics implemented in the client, including entity rendering, user input handling, viewport adjustments, and player interactions.

## Overview
The game mechanics define how the client processes game logic, updates player states, handles interpolation, and ensures smooth gameplay rendering. The client does not process physics or collision but instead reacts to updates from the server.

## Key Mechanics

### 1. Game Loop
- The game runs in a loop, handling input, updating entities, and rendering the screen.
- The main loop is structured as follows:
  1. **Process Events** (e.g., closing window, mouse input, key presses)
  2. **Send Updates** (e.g., mouse position updates sent to the server)
  3. **Apply Interpolation** (for smoother movements based on the latest server update)
  4. **Update HUD** (refresh UI elements such as leaderboard and score)
  5. **Render the World** (display updated game elements)

### 2. Player Movement and Interaction
- The client does not control movement directly but sends **normalized mouse positions** to the server.
- The server determines player movement and updates, which the client then renders.
- The viewport follows the player using **smooth interpolation** for a seamless experience.

### 3. Rendering System
- The rendering system draws all entities, including players, pellets, and the world boundary.
- Each entity is assigned a **color and shape**, which are managed through the **EntityManager**.
- The rendering cycle includes:
  - Clearing the screen.
  - Rendering the game world and entities.
  - Rendering HUD elements such as leaderboard, stats, and chatbox.

### 4. Viewport and Camera
- The viewport dynamically adjusts to follow the player's position smoothly.
- The **Viewport** component applies interpolation between the last known position and the new server update.
- The camera zoom is adjusted using the **mouse scroll wheel** to provide a better view of the surroundings.

### 5. Game HUD
- The **HUD** displays game stats such as:
  - **Score**: The total score accumulated by the player.
  - **Mass**: The total mass of the player's cells.
  - **Leaderboard**: Displays the top players ranked by mass.
- The HUD updates dynamically to reflect changes in the game state.

### 6. Mouse Input Handling
- The client captures mouse position relative to the window size.
- It normalizes the coordinates and sends them to the server.
- The server processes movement logic and sends updated positions back to the client.

### 7. Interpolation & Smooth Movement
- Because the server updates occur at a fixed frequency, the client interpolates between updates.
- This ensures smoother motion rather than relying on raw position updates.
- **Viewport interpolation** prevents choppy movement, providing a seamless gaming experience.

### 8. Entity Management
- Entities are managed through the **EntityManager**, which creates, updates, and removes them.
- The client does not simulate physics but relies on **server updates** to track cell positions.
- The game world consists of the following entities:
  - **Cells (Players & Pellets)**: Objects rendered on the game board.
  - **Leaderboard Entries**: UI elements tracking top players.
  - **HUD Elements**: Displaying important game statistics.

---

## Conclusion
The client-side game mechanics focus on rendering, smooth motion, and user interaction. Unlike the server, it does not handle game physics or collisions but instead processes updates efficiently to create a responsive and visually appealing gameplay experience.


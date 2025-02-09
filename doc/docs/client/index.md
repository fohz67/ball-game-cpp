---
title: Overview
slug: /client
---

# Game Client Documentation

This documentation covers the **Game Client** architecture, including networking, rendering, user interaction, and HUD components. Below is an overview of the different sections explaining how the client operates.

# Overview

The Game Client is responsible for connecting to the server, rendering the game world, managing player input, and updating the game state dynamically. It efficiently handles real-time updates and ensures a smooth gameplay experience.

## Key Features:
- **Networking System**: Uses `asio` to communicate with the server via TCP.
- **Game Loop**: Manages rendering, input handling, and updates at a fixed frame rate.
- **Rendering System**: Utilizes SFML for efficient drawing and smooth animations.
- **HUD & Leaderboard**: Displays real-time stats and rankings dynamically.
- **Entity Management**: Handles cell creation, deletion, and movement updates efficiently.
- **Interpolation & Viewport**: Ensures smooth motion and adaptive camera movement.

## Sections

### [1. Architecture](./client/architecture)
Understand the **networked client structure** and its communication with the server.

### [2. Network System](./client/network)
Learn how the client connects to the server, sends/receives packets, and handles network messages.

### [3. Game Mechanics](./client/game-mechanics)
Explore the **game loop**, input handling, interpolation, and in-game updates.

### [4. Rendering System](./client/rendering)
Understand how SFML is used for **drawing cells, HUD elements, and animations**.

### [5. HUD & Components](./client/components)
Explore the **HUD, leaderboard, chatbox, and UI elements** that enhance gameplay experience.

### [6. Configuration](./client/config)
Personalize your client as you like.

Each section provides in-depth explanations and structured documentation to help you understand the **Game Client** functionality.


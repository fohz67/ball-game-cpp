---
title: Architecture
slug: /client/architecture
---

# Client Architecture

The **Game Client** is responsible for rendering the game, handling player input, networking with the server, and managing the overall gameplay experience. This document provides an overview of the client's structure, including its core components and their interactions.

## Overview

The client follows a modular architecture to ensure flexibility and maintainability. The main systems include:
- **Network Layer**: Handles communication with the server using TCP.
- **Game Loop**: Manages the update cycle for rendering and game logic.
- **Rendering System**: Uses SFML to display entities and UI elements.
- **Entity Management**: Tracks all entities and updates their states.
- **HUD and Components**: Provides a user-friendly interface to display game information.

## Core Components

### 1. **Main Entry Point**
The entry point (`main.cpp`) initializes the client, processes arguments, and starts the game loop. It ensures:
- Proper argument validation using `Error::checkArgs`.
- Initialization and execution of `Client::run()`.
- Exception handling for runtime errors.

### 2. **Client Singleton**
The `Client` class acts as the central controller of the client application. It:
- Reads command-line arguments for host, port, and player nickname.
- Initializes the `NetworkClient` and establishes a connection to the server.
- Sends a `JOIN_SERVER` request.
- Starts the `GameClient`, which handles rendering and event processing.

### 3. **Networking Layer**
The `NetworkClient` handles all network interactions:
- **Establishes a connection** with the server using ASIO.
- **Sends and receives packets** asynchronously.
- **Processes incoming messages** using `ProtocolClient`.
- **Encodes and decodes messages** via `SmartBuffer`.
- **Synchronizes game state** with the server.

### 4. **Game Loop**
The `GameClient` class manages the main game loop:
- **Processes player inputs** (mouse, keyboard, events).
- **Sends network updates** (e.g., mouse movements).
- **Updates the viewport and HUD**.
- **Handles interpolation** for smooth movement.
- **Renders game objects** each frame.

### 5. **Entity Management**
The `EntityManager` tracks game objects and updates them dynamically:
- **Creates new entities** upon receiving server updates.
- **Updates positions and states** in real-time.
- **Handles removal of entities** (e.g., players leaving the game).
- **Links text-based elements** like nicknames to entities.

### 6. **HUD and Components**
Several UI components enhance the gameplay experience:
- **Leaderboard**: Displays the top players in the game.
- **HUD**: Shows stats like score, mass, and cell count.
- **Viewport**: Manages camera movement and zooming.
- **ChatBox**: Handles in-game communication.

## Summary
The client architecture is built for efficiency, scalability, and smooth gameplay. It connects to the server, maintains an updated game state, renders entities dynamically, and provides a responsive UI. Each component is modular, allowing for easy maintenance and future enhancements.

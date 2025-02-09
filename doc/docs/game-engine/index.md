---
title: Overview
slug: /game-engine
---

# Game Engine Documentation

This documentation covers the **Game Engine** architecture, including entities, components, rendering, and updates. Below is an overview of the different sections that explain how the system works.

# Overview

The Game Engine is the core framework responsible for managing game entities, rendering, components, and updates. It provides a structured way to handle game logic efficiently.

## Key Features:
- **Entity-Component System (ECS)**: Implements a modular design where each entity can hold multiple components.
- **Rendering System**: Uses SFML for drawing graphical elements efficiently.
- **Update System**: Processes logic updates for entities dynamically.
- **Component System**: Allows defining behaviors that can be attached or removed from entities.
- **Entity Management**: Handles creation, deletion, and linking of game objects.

## Sections

### [1. Architecture](./game-engine/architecture)
Understand the **Entity-Component-System (ECS)** model and how the Game Engine is structured.

### [2. Component](./game-engine/components)
Explore how **components** define entity behavior, including **position, texture, and text**.

### [3. Entity](./game-engine/entity)
Understand how entities are created, modified, and stored dynamically.

### [4. Rendering](./game-engine/rendering)
Learn how **System::render()** processes entities and displays **sprites, text, and shapes** using SFML.

### [5. Update](./game-engine/update)
Learn how the **System::update()** function modifies entity attributes dynamically, including **position, text, and textures**.
Each section contains in-depth explanations and code examples to help you understand the **Game Engine**.

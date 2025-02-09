---
title: Architecture
slug: /game-engine/architecture
---

# Game Engine Architecture

The Game Engine follows the **Entity-Component-System (ECS) model**, a common paradigm in game development that decouples game objects from behavior.

## Structure:

1. **Entities**: Unique objects in the game (e.g., a player, an enemy, a UI button).
2. **Components**: Store properties and data (e.g., position, texture, shape, text).
3. **Systems**: Process components attached to entities (e.g., rendering, updating, handling events).

### Why ECS?
- **Flexibility**: Allows easy modification and extension of game objects.
- **Performance**: Minimizes redundant processing and optimizes cache usage.
- **Scalability**: Facilitates the addition of new components without modifying existing entities.

## Example of an Entity with Components

```cpp
Entity player(1);
player.addComponent<Sprite>("player.png");
player.addComponent<Position>(100, 200);
player.addComponent<Text>("Player 1", "arial.ttf", 24);
```

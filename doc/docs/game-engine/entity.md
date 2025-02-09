---
title: Entity
slug: /game-engine/entity
---

# Entity System

Entities represent **unique game objects** that can hold multiple components.

## Creating an Entity:

```cpp
Entity player(1);
```

## Assigning Components:

```cpp
player.addComponent<Sprite>("player.png");
player.addComponent<Position>(100, 200);
```

## Checking Components:

```cpp
if (player.hasComponent<Position>()) {
    Position& pos = player.getComponent<Position>();
}
```

## Storing Entities:

Entities are usually stored in a **map** for easy retrieval:

```cpp
std::map<double, Entity> entities;
entities[1] = player;
```

Entities can be dynamically created and modified during the game.

---
title: Component System
---

# Component System

The Component System is a core part of the ECS model, allowing game objects to have properties dynamically.

## Adding Components:

```cpp
Entity player(1);
player.addComponent<Sprite>("player.png");
player.addComponent<Position>(100, 200);
player.addComponent<Text>("Player 1", "arial.ttf", 24);
```

## Retrieving Components:

```cpp
if (player.hasComponent<Position>()) {
    Position& pos = player.getComponent<Position>();
    std::cout << "X: " << pos.getPositionX() << ", Y: " << pos.getPositionY() << std::endl;
}
```

## Removing Components:

```cpp
player.removeComponent<Sprite>();
```

Components provide a way to **store entity attributes** without tightly coupling behavior to the entity itself.

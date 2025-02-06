---
title: Rendering System
---

# Rendering System

The rendering system is responsible for drawing game objects on the screen using SFML. It processes entities that have renderable components and updates their visual state.

## How Rendering Works:

1. The game loop calls `System::render()`.
2. The `render()` function iterates over all entities.
3. If an entity has a **Sprite, Text, or Shape component**, it is drawn to the window.

## Rendering Pipeline:

```cpp
System system;
std::map<double, Entity> entities;

sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

while (window.isOpen()) {
    window.clear();
    system.render(window, entities);
    window.display();
}
```

## Components Rendered:
- **Sprite**: `entity.hasComponent<Sprite>()`
- **Text**: `entity.hasComponent<Text>()`
- **Shape**: `entity.hasComponent<Shape>()`

The rendering system ensures efficient draw calls and handles transformations dynamically.

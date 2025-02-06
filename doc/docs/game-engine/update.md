---
title: Update System
---

# Update System

The update system processes game logic and synchronizes entity states.

## Updating Entity Position:

```cpp
system.updateEntityPosition(entityId, entities, {x, y}, posId);
```

## Changing Text:

```cpp
system.updateText(entity, "New Score: 100");
```

## Modifying Text Size:

```cpp
system.updateTextSize(entityId, entities, 24);
```

## Updating Text Font:

```cpp
system.updateTextFont(entity, "arial.ttf");
```

The update system ensures that **all entities remain synchronized** with game logic.

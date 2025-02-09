---
title: Components
slug: /client/components
---

# Client Components Documentation

This document describes the various components used in the client-side of the Ball Game. Components are modular elements that define the properties and behavior of entities in the game.

## Overview
The client-side architecture follows a component-based system to define entity attributes, such as visuals, position, movement, and interaction with the game world. Below are the key components used in the client.

---

## 1. **HUD (Heads-Up Display)**
The HUD component is responsible for rendering real-time game information, including player statistics, the leaderboard, and other UI elements.

- **Displays game stats (score, mass, cell count).**
- **Manages real-time updates for UI elements.**
- **Handles UI styling, such as font, color, and layout.**

### **Main Properties**
| Property       | Type   | Description                      |
|---------------|--------|----------------------------------|
| `backgroundColor` | `vector double` | HUD background color. |
| `padding` | `double` | Padding around HUD elements. |
| `textColor` | `vector double` | Color of text elements. |

---

## 2. **Leaderboard**
The leaderboard component tracks the top players in the game based on mass or score.

- **Updates dynamically as players gain mass.**
- **Stores and sorts player rankings.**
- **Renders leaderboard data on the HUD.**

### **Main Properties**
| Property       | Type   | Description                      |
|---------------|--------|----------------------------------|
| `maxEntries` | `int` | Maximum number of players displayed. |
| `title` | `std::string` | Leaderboard title. |
| `contentSize` | `double` | Font size for player names. |

---

## 3. **Viewport**
The viewport controls the camera's position and movement within the game world, allowing for smooth tracking of the player's entity.

- **Interpolates camera movement for smoother gameplay.**
- **Centers the view on the player's position.**
- **Handles zoom functionality.**

### **Main Properties**
| Property       | Type   | Description                      |
|---------------|--------|----------------------------------|
| `previousViewport` | `pair double,double` | Stores previous camera position for interpolation. |
| `interpolationFactor` | `double` | Determines smoothness of camera movement. |

---

## 4. **Zoom**
The zoom component manages zooming in and out within the game world, ensuring smooth scaling of the viewport.

- **Adjusts zoom level dynamically.**
- **Prevents excessive zooming.**

### **Main Properties**
| Property       | Type   | Description                      |
|---------------|--------|----------------------------------|
| `zoomSpeed` | `double` | Determines zoom intensity. |

---

## 5. **Hotkeys**
Hotkeys manage keyboard and mouse input, allowing players to interact with the game through specific commands.

- **Listens for key and mouse inputs.**
- **Processes hotkey events like zooming or toggling UI elements.**

---

## Summary
These components work together to provide a smooth and interactive client-side experience. Each component is responsible for a different aspect of the game's functionality, ensuring a modular and scalable design.

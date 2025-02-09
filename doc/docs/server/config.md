---
title: Configuration
slug: /server/config
---

## Overview
The `Config` struct defines all essential configurations for the game, including network settings, gameplay parameters, world dimensions, and various mechanics related to players, bots, and cells. These settings allow for easy modifications and tuning of the game behavior.

---

## 1. Game Configuration
### `Config::Game`
- **`FREQUENCY` (int)**: Defines the tick rate of the game loop (in milliseconds). Default: `50`.
- **`DEBUG` (bool)**: Enables or disables debug mode. Default: `false`.

---

## 2. Network Configuration
### `Config::Network`
- **`PORT` (int)**: The TCP port used for server-client communication. Default: `12345`.
- **`FREQUENCY` (int)**: The network update rate (in milliseconds). Default: `50`.
- **`MAX_SIZE` (int)**: The maximum size (in bytes) allowed for a single network packet. Default: `1024`.

---

## 3. Quadtree Configuration
### `Config::Quadtree`
- **`MAX_OBJECTS` (int)**: The maximum number of objects per quadtree node before subdivision. Default: `10`.
- **`MAX_LEVELS` (int)**: The maximum depth of the quadtree before no further subdivision occurs. Default: `5`.

---

## 4. Gameplay Configuration
### `Config::Gameplay`

### World Settings
#### `Config::Gameplay::World`
- **`SIZE` (uint16_t)**: The size of the game world. Default: `1000.0f`.

### Cell Mechanics
#### `Config::Gameplay::Cell`
- **`SPAWN_MASS` (double)**: The initial mass of a newly created cell. Default: `5000.0f`.
- **`SPEED` (double)**: The base speed of a cell. Default: `3.0f`.
- **`DECREASE_SPEED_THRESHOLD` (double)**: The threshold at which speed starts decreasing due to mass increase. Default: `0.05f`.
- **`DECAY_RATE` (double)**: The rate at which cells lose mass over time. Default: `0.0001`.
- **`DECAY_EXPONENT` (double)**: Exponent applied to mass decay calculations. Default: `1.2`.
- **`DECAY_SCALING` (double)**: Scaling factor applied to mass decay. Default: `2.5`.
- **`MIN_MASS` (double)**: The minimum mass a cell can have before it is removed. Default: `10.0`.

### Bot AI Settings
#### `Config::Gameplay::Bot`
- **`COUNT` (int)**: The number of AI-controlled bots in the game. Default: `15`.
- **`MASS` (double)**: The default mass of a bot upon spawning. Default: `5000.0f`.
- **`ATTACK_INTENSITY` (float)**: The intensity of bot aggression when attacking. Default: `1.5f`.
- **`DEFENSE_INTENSITY` (float)**: The intensity of bot movement when escaping danger. Default: `2.0f`.
- **`RANDOM_MOVEMENT_INTENSITY` (float)**: The randomness of bot wandering movements. Default: `1.0f`.
- **`HUNT_RADIUS` (float)**: The maximum distance at which a bot will detect prey. Default: `1200.0f`.
- **`ESCAPE_RADIUS` (float)**: The distance within which bots will flee from larger threats. Default: `500.0f`.
- **`CHASE_ABORT_DISTANCE` (float)**: The distance at which bots abandon their chase. Default: `800.0f`.
- **`MASS_ADVANTAGE_TO_ATTACK` (float)**: The ratio of mass required for bots to decide to attack. Default: `0.8f`.
- **`MASS_DISADVANTAGE_TO_FLEE` (float)**: The ratio of mass required for bots to decide to flee. Default: `1.3f`.
- **`RANDOM_WANDER_SPEED` (float)**: The movement speed of a bot when wandering randomly. Default: `2.0f`.
- **`WORLD_PADDING` (float)**: The minimum distance from the world boundary before bots turn away. Default: `100.0f`.
- **`MINIMUM_PELLET_HUNT` (float)**: The minimum number of pellets bots will consume before switching to another strategy. Default: `400.0f`.
- **`ABANDON_TARGET_TIME` (float)**: Time (in milliseconds) before a bot gives up pursuing a target. Default: `3000.0f`.

### Eating Mechanics
#### `Config::Gameplay::Eat`
- **`RESOLVE_FACTOR` (double)**: Multiplier for determining if one cell can consume another. Default: `1.2f`.
- **`RESOLVE_OVERLAP` (double)**: Percentage overlap required for eating to be successful. Default: `0.2f`.

### Pellet Settings
#### `Config::Gameplay::Pellet`
- **`COUNT` (int)**: The total number of pellets spawned in the game world. Default: `3000`.
- **`MASS` (double)**: The mass of each pellet. Default: `2.0f`.
- **`EAT_FACTOR` (double)**: The multiplier applied when a player eats a pellet. Default: `10.0f`.

### Player Settings
#### `Config::Gameplay::Player`
- **`COLOR` (vector double)**: The default RGBA color of a player's cell. Default: `{255, 255, 255, 255}`.
- **`MAX_NICKNAME_LENGTH` (int)**: The maximum number of characters allowed in a player's nickname. Default: `20`.
- **`NICKNAME_TOO_LONG_FALLBACK` (string)**: Default nickname used if a chosen nickname is too long. Default: `"Long Name"`.
- **`NICKNAME_EMPTY_FALLBACK` (string)**: Default nickname used if the player does not enter a name. Default: `"An Unnamed Cell"`.

### Leaderboard Settings
#### `Config::Gameplay::Leaderboard`
- **`MAX_ENTRIES` (int)**: The maximum number of players displayed on the leaderboard. Default: `10`.

---

## Summary
The `Config` struct centralizes all adjustable game settings, making it easy to fine-tune different aspects of gameplay, networking, and world properties. By modifying these values, developers can optimize performance, adjust game balance, and create new gameplay experiences.

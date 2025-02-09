# Installation Guide

## Prerequisites

Before installing **Ball Game C++**, ensure that you have the following dependencies installed:

- A C++ compiler supporting **C++20**
- **CMake** for build generation
- **SFML** for graphics rendering
- **ASIO** for networking
- **Git** for cloning the repository

---

## Cloning the Repository

To get the latest version of the project, **clone** the repository with submodules:

```bash
git clone --recurse-submodules git@github.com:fohz67/ball-game-cpp.git
cd ball-game-cpp
```

> ⚠️ **Important:** The `--recurse-submodules` flag is required to fetch dependencies correctly.

---

## Building the Project

Once inside the project directory, execute the following command to **build** the game:

```bash
./scripts/build.sh
```

This script will:
- Generate the necessary build files using **CMake**
- Compile both the server and client

After a successful build, the compiled binaries will be available in the `build/` directory.

---

## Running the Game

### Starting the Server

Run the following command to **start the server**:

```bash
./build/server/Server
```

### Starting the Client

Open a new terminal and execute:

```bash
./build/client/Client
```

By default, the client will connect to `127.0.0.1:12345`. If you want to connect to a different server, specify the IP and port:

```bash
./build/client/Client -s <server_ip> -p <port> -n <nickname>
```

---

## Project Structure

- `assets/` → Game resources (textures, sounds, fonts)
- `client/` → Client-side game logic and rendering
- `server/` → Server-side game logic and networking
- `asio/` → Asio submodule files
- `smart-buffer-cpp/` → SmartBuffer submodule files
- `SFML/` → SFML submodule files
- `game_engine/` → Core engine handling rendering, physics, and entities
- `scripts/` → Useful scripts
- `doc/` → Docusaurus files

This completes the setup for **Ball Game C++**. Enjoy the game!


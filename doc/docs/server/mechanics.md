---
title: Mechanics
slug: /server/mechanics
---

## Overview
This document provides an in-depth explanation of the core game mechanics, including the game loop, cell decay, collisions, eating mechanics, Fast Inverse Square Root (FIS), and vector calculations.

---

## 1. Game Loop
The game operates on a continuous **update loop** that processes all game elements at a fixed interval. This loop ensures smooth gameplay by:
- Updating player positions based on input (mouse movement or AI behavior).
- Managing cell behavior, including movement, growth, and decay.
- Handling interactions like eating and collisions.
- Sending game state updates to clients.

### Loop Execution Order:
1. **Update Cells:** Move cells, apply decay, and handle physics.
2. **Process Collisions:** Check interactions between cells and resolve them.
3. **Update Leaderboard:** Rank players based on their mass.
4. **Send Network Updates:** Transmit the new game state to all connected clients.
5. **Wait for Next Tick:** Maintain a consistent update rate to avoid lag.

---

## 2. Cell Decay
Cells continuously **lose mass over time** to prevent infinite growth and keep the game balanced.
- The decay rate is proportional to the cell's mass.
- The larger a cell, the faster it loses mass.
- The decay function follows an **exponential decay curve**, reducing mass by a percentage each frame.
- If a cell’s mass drops below a threshold, it reaches its **minimum playable size**.

**Formula:**
```
NewMass = CurrentMass - (DecayRate * CurrentMass)
```

---

## 3. Collisions
Collisions are fundamental to cell interactions. The game processes collisions in two key ways:

### **Cell-Cell Collisions**
- A cell cannot pass through another.
- Larger cells can absorb smaller cells if they meet the eating conditions.
- Movement is restricted if two cells are overlapping to prevent clipping.

### **Cell-Boundary Collisions**
- The game world is a finite space with boundaries.
- If a cell reaches the world’s edge, its movement is constrained.
- Collisions with the boundary adjust the cell’s position to stay within the playable area.

---

## 4. Eating Mechanics
Cells can **consume** smaller entities to grow. The process follows these rules:
1. **Size Comparison:** A cell can only eat another if it is **significantly larger**.
2. **Distance Check:** The larger cell must be **close enough** to engulf the smaller one.
3. **Mass Transfer:** The eaten cell's mass is added to the consuming cell.

### **Pellet Consumption**
- Small cells can eat **static pellets** spread across the map.
- Pellets provide a small mass boost but do not alter gameplay significantly.

### **Player vs. Player Eating**
- A cell must be **at least 1.25x larger** than another to consume it.
- The mass of the eaten cell is added to the absorbing cell.
- Eaten players are **eliminated** and must respawn.

---

## 5. Fast Inverse Square Root (FIS)
The **Fast Inverse Square Root** algorithm (FIS) is an optimized method to compute `1 / sqrt(x)`, used for distance and magnitude calculations.

### **Why Use FIS?**
- Reduces CPU load compared to traditional `sqrt()` calls.
- Optimized using bit manipulation for near-instant computation.
- Used in distance normalization and movement calculations.

### **Implementation**
FIS uses a magic number (`0x5f3759df`) to estimate the inverse square root quickly:
```
i = 0x5f3759df - (i >> 1); // Bit-level hack for sqrt approximation
```
This method is used extensively in collision detection and vector normalization.

---

## 6. Vector2 Operations
The `Vector2` class is essential for handling **positions, movement, and physics**.

### **Core Operations**
- **Addition & Subtraction:** Used to move objects.
- **Multiplication & Division:** Used for scaling movements.
- **Dot Product:** Measures the similarity of two vectors (e.g., direction checks).
- **Normalization:** Converts a vector to a unit direction (used in movement logic).
- **Magnitude:** Calculates the length of a vector, used in collision and distance calculations.

### **Example Use Cases**
- Moving cells based on mouse input:
```
Vector2 direction = (mousePosition - cellPosition).normalized();
cellPosition += direction * cellSpeed;
```
- Checking if a cell can eat another:
```
double distance = (cell1.position - cell2.position).magnitude();
if (distance < cell1.radius - cell2.radius * 0.8) {
    cell1.absorb(cell2);
}
```

---

## Conclusion
These mechanics form the foundation of the game, ensuring fair play, competitive interactions, and smooth performance. The balance between **growth, decay, and collisions** creates engaging gameplay where players must strategically **navigate, consume, and survive** in the ever-changing world.

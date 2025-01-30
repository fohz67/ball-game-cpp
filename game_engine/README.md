# R-Type Project - Game Engine Overview

This document provides an overview of the main components used in the R-Type project. Each component is designed to handle specific functionality such as health management, physics, graphics rendering, or user interaction.

## Table of Contents
<br>

1. [Entity](#entity)
    - [Description](#description)
    - [Main features](#main-features)
    - [Methods](#methods)
        - [Construtor](#constructors)
        - [Component Management](#component-management)
        - [Utilities](#utilities)
<br>
<br>
<br>

2. [Core Components](#core-components)
    - [Health](#health)
    - [Position](#position)
    - [Velocity](#velocity)
3. [Physics Components](#physics-components)
    - [Rigidbody](#rigidbody)
    - [Collider](#collider)
4. [Graphics Components](#graphics-components)
    - [Renderable](#renderable)
    - [Sprite](#sprite)
    - [Animation](#animation)
    - [Text](#text)
    - [Color](#color)
5. [UI Components](#ui-components)
    - [Button](#button)
6. [Gameplay Components](#gameplay-components)
    - [Bullet](#bullet)
    - [Input](#input)
7. [Audio Components](#audio-components)
    - [Sound](#sound)
    
<br>

---

<br>

## Entity

## Description
The `Entity` is the core structure of the game engine, serving as a container for components. Each entity represents a game object, such as a player, enemy, or projectile. With its component-based system, `Entity` offers maximum flexibility by allowing functionalities to be added, removed, and managed dynamically.

## Main Features
- **Dynamic Component Management**: Add and remove components on the fly.
- **Unique Association with an ID**: Each entity has a unique identifier.
- **Component Listing**: View all components attached to an entity.
- **Secure Component Access**: Ensures each component is unique to avoid conflicts.

## Methods

### Constructors
- `Entity(int id)`: Initializes an entity with an identifier.  
- `Entity(int id, Args&&... args)`: Initializes an entity with an identifier and initial components.

### Component Management
- `addComponent(ComponentType component)`: Adds a component to the entity. Throws an error if the component already exists.  
- `removeComponent<ComponentType>()`: Removes a specific component. Throws an error if the component is not found.  
- `getComponent<ComponentType>()`: Retrieves a reference to the requested component. Throws an error if the component is not found.

### Utilities
- `displayComponents()`: Displays all components attached to the entity.  
- `getEntityId()`: Returns the unique ID of the entity.

---

<br>
<br>
<br>
<br>
<br>

## Core Components

### Health
- **Description**: Manages the health system of an entity, including current and maximum health.
- **Attributes**:
  - `_currentHp`: Current health points.
  - `_maxHp`: Maximum health points (default: 100).
- **Functions**:
  - `getCurrentHp()`: Returns the current health points.
  - `setCurrentHp(int currentHp)`: Sets the current health points.
  - `getMaxHp()`: Returns the maximum health points.
  - `setMaxHp(int maxHp)`: Sets the maximum health points.
  - `getInfo()`: Returns health informations.

### Position
- **Description**: Tracks the 2D position of an entity using `x` and `y` coordinates.
- **Attributes**:
  - `_x`: Horizontal position.
  - `_y`: Vertical position.
- **Functions**:
  - `getPositionX()`: Returns the horizontal position.
  - `getPositionY()`: Returns the vertical position.
  - `setPositionX(float x)`: Sets the horizontal position.
  - `setPositionY(float y)`: Sets the vertical position.
  - `getInfo()`: Returns position informations.

### Velocity
- **Description**: Represents the movement speed of an entity in 2D space.
- **Attributes**:
  - `_x`: Horizontal velocity.
  - `_y`: Vertical velocity.
- **Functions**:
  - `getVelocityX()`: Returns the horizontal velocity.
  - `getVelocityY()`: Returns the vertical velocity.
  - `setVelocityX(float x)`: Sets the horizontal velocity.
  - `setVelocityY(float y)`: Sets the vertical velocity.
  - `getInfo()`: Returns velocity informations.

---

## Physics Components

### Rigidbody
- **Description**: Represents the physics body of an entity with attributes for mass, drag, gravity, and forces.
- **Attributes**:
  - `_mass`: Entity mass.
  - `_drag`: Resistance factor.
  - `_gravityScale`: Gravity scale.
  - `_forceX`: Horizontal force.
  - `_forceY`: Vertical force.
  - `_rect`: Bounding rectangle (for physics).
  - `_isLoad`: Indicates if the Rigidbody is active.
- **Functions**:
  - `getMass()`: Returns the mass of the Rigidbody.
  - `setMass(float mass)`: Sets the mass of the Rigidbody.
  - `getDrag()`: Returns the drag factor.
  - `setDrag(float drag)`: Sets the drag factor.
  - `getGravityScale()`: Returns the gravity scale.
  - `setGravityScale(float gravityScale)`: Sets the gravity scale.
  - `getForceX()`: Returns the horizontal force.
  - `setForceX(float forceX)`: Sets the horizontal force.
  - `getForceY()`: Returns the vertical force.
  - `setForceY(float forceY)`: Sets the vertical force.
  - `getIsLoad()`: Returns whether the Rigidbody is active.
  - `setIsLoad(bool isLoad)`: Activates or deactivates the Rigidbody.
  - `getRect()`:  Returns the sf::rect.
  - `setRect(sf::rect<int> rect)`: Sets the rect of the RigidBody
  - `getInfo()`: Returns RigidBody informations.

### Collider
- **Description**: Defines collision boundaries for an entity using a bounding box.
- **Attributes**:
  - `_size`: Collider size.
  - `_rect`: Bounding rectangle (for collision).
  - `_isLoad`: Indicates if the Collider is active.
- **Functions**:
  - `getCollider()`: Returns the collider's size and position.
  - `setCollider(std::vector<double> size)`: Sets the collider's size.
  - `getIsLoad()`: Returns whether the Collider is active.
  - `setIsLoad(bool isLoad)`: Activates or deactivates the Collider.
  - `getRect()`:  Returns the sf::rect.
  - `setRect(sf::rect<int> rect)`: Sets the rect of the Collider
  - `getInfo()`: Returns Collider informations.

---

## Graphics Components

### Renderable
- **Description**: Determines whether an entity is visible in the game world.
- **Attributes**:
  - `_isVisible`: Visibility flag.
- **Functions**:
  - `getIsVisible()`: Returns whether the entity is visible.
  - `setIsVisible(bool isVisible)`: Sets the visibility of the entity.
  - `getInfo()`: Returns Renderable informations.

### Sprite
- **Description**: Handles the visual representation of an entity, including its texture path and size.
- **Attributes**:
  - `_texturePath`: Path to the texture file.
  - `_size`: Sprite size (width and height).
  - `_sprite`: Main sprite.
  - `_isLoad`: Indicates if the Sprite is active.
- **Functions**:
  - `getTexturePath()`: Returns the texture file path.
  - `setTexturePath(std::string texturePath)`: Sets the texture file path.
  - `getSize()`: Returns the sprite size.
  - `setSize(std::vector<double> size)`: Sets the sprite size.
  - `getSprite()`: Returns the  sprite.
  - `setSprite(sf::Sprite sprite)`: Sets the new sprite.
  - `getIsLoad()`: Returns whether the Sprite is active.
  - `setIsLoad(bool isLoad)`: Activates or deactivates the Sprite.
  - `getInfo()`: Returns Sprite informations.

### Animation
- **Description**: Handles frame-based animations for entities.
- **Attributes**:
  - `_currentFrame`: Current animation frame.
  - `_frameDuration`: Duration for each frame.
  - `_elapsedTime`: Time elapsed since the last frame update.
- **Functions**:
  - `getCurrentFrame()`: Returns the current frame index.
  - `setCurrentFrame(int currentFrame)`: Sets the current frame index.
  - `getFrameDuration()`: Returns the duration of each frame.
  - `setFrameDuration(float frameDuration)`: Sets the duration of each frame.
  - `getElapsedTime()`: Returns the elapsed time since the last frame update.
  - `setElapsedTime(float elapsedTime)`: Sets the elapsed time since the last frame update.
  - `getInfo()`: Returns Animation informations.


### Text
- **Description**: Manages the display of text on the screen.
- **Attributes**:
  - `_initText`: Init text content.
  - `_text`: Text content.
  - `_font`: Font text.
  - `_isLoad`: Indicates if the Text is active.
- **Functions**:
  - `getText()`: Returns the current text content.
  - `setText(std::string text)`: Sets the text content.ù
  - `getIsLoad()`: Returns whether the Text is active.
  - `setIsLoad(bool isLoad)`: Activates or deactivates the Text.
  - `getInfo()`: Returns Text informations.


### Color
- **Description**: Defines the color of an entity using RGBA values.
- **Attributes**:
  - `_initColor`: Init vector storing color components (R, G, B, A).
  - `_color`: Color components.
- **Functions**:
  - `getColor()`: Returns the current color.
  - `setColor(std::vector<double> color)`: Sets the color components.
  - `getInfo()`: Returns Color informations.

---

## UI Components

### Button
- **Description**: Represents a clickable button in the user interface.
- **Attributes**:
  - `_text`: Button text.
  - `_size`: Button size.
  - `enum shape`: { Circle, Rectangle }.
  - `_button`: Rectangle shape.
  - `_isLoad`: Indicates if the Button is active.
- **Functions**:
  - `getText()`: Returns the button text.
  - `setText(std::string text)`: Sets the button text.
  - `getSize()`: Returns the button size.
  - `setSize(std::vector2f size)`: Sets the button size.
  - `getIsLoad()`: Returns whether the Button is active.
  - `setIsLoad(bool isLoad)`: Activates or deactivates the Button.
  - `getInfo()`: Returns Button informations.

---

## Gameplay Components

### Bullet
- **Description**: Manages properties of a bullet, such as damage and the source entity.
- **Attributes**:
  - `_damage`: Bullet damage.
  - `_sourceEntity`: Entity that fired the bullet.
- **Functions**:
  - `getDamage()`: Returns the bullet's damage.
  - `setDamage(int damage)`: Sets the bullet's damage.
  - `getInfo()`: Returns Bullet informations.

### Input
- **Description**: Tracks player input for movement and actions.
- **Attributes**:
  - `_up`: Movement up.
  - `_right`: Movement right.
  - `_left`: Movement left.
  - `_down`: Movement down.
  - `_attack`: Attack state.
  - `_autoFire`: Auto-fire state.
- **Functions**:
  - `getUp()`: Returns if the "up" input is active.
  - `getRight()`: Returns if the "right" input is active.
  - `getLeft()`: Returns if the "left" input is active.
  - `getDown()`: Returns if the "down" input is active.
  - `getAttack()`: Returns if the attack input is active.
  - `getAutoFire()`: Returns if auto-fire is enabled.
  - `setUp(bool up)`: Sets the "up" input state.
  - `setRight(bool right)`: Sets the "right" input state.
  - `setLeft(bool left)`: Sets the "left" input state.
  - `setDown(bool down)`: Sets the "down" input state.
  - `setAttack(bool attack)`: Sets the attack input state.
  - `setAutoFire(bool autoFire)`: Enables or disables auto-fire.ù
  - `getInfo()`: Returns Input informations.

---

## Audio Components

### Sound
- **Description**: Manages sound effects for entities.
- **Attributes**:
  - `_soundFile`: Path to the sound file.
  - `_volume`: Volume level.
  - `buffer`: Sound buffer.
  - `sound`: Main sound.
  - `_isLoad`: Indicates if the Sound is active.
- **Functions**:
  - `getSoundFile()`: Returns the sound file path.
  - `setSoundFile(std::string soundFile)`: Sets the sound file path.
  - `getVolume()`: Returns the volume level.
  - `setVolume(int volume)`: Sets the volume level.
  - `getIsLoad()`: Returns whether the Sound is active.
  - `setIsLoad(bool isLoad)`: Activates or deactivates the Sound.
  - `getInfo()`: Returns Sound informations.

"use strict";(self.webpackChunkBall_Game_C_Documentation=self.webpackChunkBall_Game_C_Documentation||[]).push([[849],{6164:e=>{e.exports=JSON.parse('{"version":{"pluginId":"default","version":"current","label":"Next","banner":null,"badge":false,"noIndex":false,"className":"docs-version-current","isLast":true,"docsSidebars":{"tutorialSidebar":[{"type":"category","label":"Install","collapsible":true,"collapsed":false,"items":[{"type":"link","label":"Installation Guide","href":"/docs/install/","docId":"install/index","unlisted":false}]},{"type":"category","label":"Game Engine","collapsible":true,"collapsed":false,"items":[{"type":"link","label":"Overview","href":"/docs/game-engine","docId":"game-engine/index","unlisted":false},{"type":"link","label":"Architecture","href":"/docs/game-engine/architecture","docId":"game-engine/architecture","unlisted":false},{"type":"link","label":"Components","href":"/docs/game-engine/components","docId":"game-engine/components","unlisted":false},{"type":"link","label":"Entity","href":"/docs/game-engine/entity","docId":"game-engine/entity","unlisted":false},{"type":"link","label":"Rendering","href":"/docs/game-engine/rendering","docId":"game-engine/rendering","unlisted":false},{"type":"link","label":"Update","href":"/docs/game-engine/update","docId":"game-engine/update","unlisted":false}]},{"type":"category","label":"Protocol","collapsible":true,"collapsed":false,"items":[{"type":"link","label":"Protocol","href":"/docs/protocol","docId":"protocol/index","unlisted":false}]},{"type":"category","label":"Server","collapsible":true,"collapsed":false,"items":[{"type":"link","label":"Overview","href":"/docs/server","docId":"server/index","unlisted":false},{"type":"link","label":"Network","href":"/docs/server/network","docId":"server/network","unlisted":false},{"type":"link","label":"Components","href":"/docs/server/components","docId":"server/components","unlisted":false},{"type":"link","label":"Mechanics","href":"/docs/server/mechanics","docId":"server/mechanics","unlisted":false},{"type":"link","label":"Optimizations","href":"/docs/server/optimizations","docId":"server/optimizations","unlisted":false},{"type":"link","label":"Configuration","href":"/docs/server/config","docId":"server/config","unlisted":false}]},{"type":"category","label":"Client","collapsible":true,"collapsed":false,"items":[{"type":"link","label":"Overview","href":"/docs/client","docId":"client/index","unlisted":false},{"type":"link","label":"Architecture","href":"/docs/client/architecture","docId":"client/architecture","unlisted":false},{"type":"link","label":"Client Network","href":"/docs/client/network","docId":"client/network","unlisted":false},{"type":"link","label":"Components","href":"/docs/client/components","docId":"client/components","unlisted":false},{"type":"link","label":"Game Mechanics","href":"/docs/client/game-mechanics","docId":"client/game-mechanics","unlisted":false},{"type":"link","label":"Rendering","href":"/docs/client/rendering","docId":"client/rendering","unlisted":false},{"type":"link","label":"Configuration","href":"/docs/server/config","docId":"server/config","unlisted":false}]}]},"docs":{"blank":{"id":"blank","title":"Yo","description":""},"client/architecture":{"id":"client/architecture","title":"Architecture","description":"The Game Client is responsible for rendering the game, handling player input, networking with the server, and managing the overall gameplay experience. This document provides an overview of the client\'s structure, including its core components and their interactions.","sidebar":"tutorialSidebar"},"client/components":{"id":"client/components","title":"Components","description":"This document describes the various components used in the client-side of the Ball Game. Components are modular elements that define the properties and behavior of entities in the game.","sidebar":"tutorialSidebar"},"client/config":{"id":"client/config","title":"Configuration","description":"Cette section d\xe9crit la configuration du client utilis\xe9e pour le Ball Game. La configuration d\xe9finit les param\xe8tres du jeu, de la fen\xeatre, du r\xe9seau et de l\'interface utilisateur."},"client/game-mechanics":{"id":"client/game-mechanics","title":"Game Mechanics","description":"This document explains the game mechanics implemented in the client, including entity rendering, user input handling, viewport adjustments, and player interactions.","sidebar":"tutorialSidebar"},"client/index":{"id":"client/index","title":"Overview","description":"This documentation covers the Game Client architecture, including networking, rendering, user interaction, and HUD components. Below is an overview of the different sections explaining how the client operates.","sidebar":"tutorialSidebar"},"client/network":{"id":"client/network","title":"Client Network","description":"The Client Network module is responsible for handling all network communication between the game client and the server. It manages sending and receiving packets, handling protocol messages, and maintaining a stable connection.","sidebar":"tutorialSidebar"},"client/rendering":{"id":"client/rendering","title":"Rendering","description":"The Rendering System in the client is responsible for displaying the game world, entities, and UI elements efficiently. It leverages SFML to handle real-time rendering and ensures smooth graphical updates.","sidebar":"tutorialSidebar"},"game-engine/architecture":{"id":"game-engine/architecture","title":"Architecture","description":"The Game Engine follows the Entity-Component-System (ECS) model, a common paradigm in game development that decouples game objects from behavior.","sidebar":"tutorialSidebar"},"game-engine/components":{"id":"game-engine/components","title":"Components","description":"The Component System is a core part of the ECS model, allowing game objects to have properties dynamically.","sidebar":"tutorialSidebar"},"game-engine/entity":{"id":"game-engine/entity","title":"Entity","description":"Entities represent unique game objects that can hold multiple components.","sidebar":"tutorialSidebar"},"game-engine/index":{"id":"game-engine/index","title":"Overview","description":"This documentation covers the Game Engine architecture, including entities, components, rendering, and updates. Below is an overview of the different sections that explain how the system works.","sidebar":"tutorialSidebar"},"game-engine/rendering":{"id":"game-engine/rendering","title":"Rendering","description":"The rendering system is responsible for drawing game objects on the screen using SFML. It processes entities that have renderable components and updates their visual state.","sidebar":"tutorialSidebar"},"game-engine/update":{"id":"game-engine/update","title":"Update","description":"The update system processes game logic and synchronizes entity states.","sidebar":"tutorialSidebar"},"install/index":{"id":"install/index","title":"Installation Guide","description":"Prerequisites","sidebar":"tutorialSidebar"},"protocol/index":{"id":"protocol/index","title":"Protocol","description":"This document provides an overview of the communication protocol for the Ball Game server. It defines the purpose, payload, and transmission method for each operation code (OpCode).","sidebar":"tutorialSidebar"},"server/components":{"id":"server/components","title":"Components","description":"Overview","sidebar":"tutorialSidebar"},"server/config":{"id":"server/config","title":"Configuration","description":"Overview","sidebar":"tutorialSidebar"},"server/index":{"id":"server/index","title":"Overview","description":"This documentation provides an in-depth explanation of the Ball Game architecture, including networking, components, game mechanics, and optimizations. Below is an overview of the different sections that explain how the system works.","sidebar":"tutorialSidebar"},"server/mechanics":{"id":"server/mechanics","title":"Mechanics","description":"Overview","sidebar":"tutorialSidebar"},"server/network":{"id":"server/network","title":"Network","description":"This document provides an overview of the network architecture used in the Ball Game project. It explains the TCP-based communication, packet structure, message handling, protocol design, and the use of ASIO for networking.","sidebar":"tutorialSidebar"},"server/optimizations":{"id":"server/optimizations","title":"Optimizations","description":"This document provides an in-depth explanation of how memory management, threading, object pooling, and performance optimizations are handled in the game server.","sidebar":"tutorialSidebar"}}}}')}}]);
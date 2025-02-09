module.exports = {
  tutorialSidebar: [
    {
      type: "category",
      label: "Install",
      collapsible: true,
      collapsed: false,
      items: [
        "install/index",
      ],
    },
    {
      type: "category",
      label: "Game Engine",
      collapsible: true,
      collapsed: false,
      items: [
        "game-engine/index",
        "game-engine/architecture",
        "game-engine/components",
        "game-engine/entity",
        "game-engine/rendering",
        "game-engine/update",
      ],
    },
    {
      type: "category",
      label: "Protocol",
      collapsible: true,
      collapsed: false,
      items: [
        "protocol/index"
      ],
    },
    {
      type: "category",
      label: "Server",
      collapsible: true,
      collapsed: false,
      items: [
        "server/index",
        "server/network",
        "server/components",
        "server/mechanics",
        "server/optimizations",
        "server/config"
      ],
    },
    {
      type: "category",
      label: "Client",
      collapsible: true,
      collapsed: false,
      items: [
        "client/index",
        "client/architecture",
        "client/network",
        "client/components",
        "client/game-mechanics",
        "client/rendering",
        "server/config"
      ],
    }
  ],
};

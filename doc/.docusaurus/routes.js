import React from 'react';
import ComponentCreator from '@docusaurus/ComponentCreator';

export default [
  {
    path: '/ball-game-cpp/docs',
    component: ComponentCreator('/ball-game-cpp/docs', '33c'),
    routes: [
      {
        path: '/ball-game-cpp/docs',
        component: ComponentCreator('/ball-game-cpp/docs', '13a'),
        routes: [
          {
            path: '/ball-game-cpp/docs',
            component: ComponentCreator('/ball-game-cpp/docs', '9ce'),
            routes: [
              {
                path: '/ball-game-cpp/docs/blank',
                component: ComponentCreator('/ball-game-cpp/docs/blank', '51e'),
                exact: true
              },
              {
                path: '/ball-game-cpp/docs/client',
                component: ComponentCreator('/ball-game-cpp/docs/client', '9e2'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/client/architecture',
                component: ComponentCreator('/ball-game-cpp/docs/client/architecture', '903'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/client/components',
                component: ComponentCreator('/ball-game-cpp/docs/client/components', '724'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/client/config',
                component: ComponentCreator('/ball-game-cpp/docs/client/config', '7b7'),
                exact: true
              },
              {
                path: '/ball-game-cpp/docs/client/game-mechanics',
                component: ComponentCreator('/ball-game-cpp/docs/client/game-mechanics', 'a51'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/client/network',
                component: ComponentCreator('/ball-game-cpp/docs/client/network', '2e9'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/client/rendering',
                component: ComponentCreator('/ball-game-cpp/docs/client/rendering', 'f7b'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/game-engine',
                component: ComponentCreator('/ball-game-cpp/docs/game-engine', '9bd'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/game-engine/architecture',
                component: ComponentCreator('/ball-game-cpp/docs/game-engine/architecture', 'c66'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/game-engine/components',
                component: ComponentCreator('/ball-game-cpp/docs/game-engine/components', 'e7b'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/game-engine/entity',
                component: ComponentCreator('/ball-game-cpp/docs/game-engine/entity', '189'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/game-engine/rendering',
                component: ComponentCreator('/ball-game-cpp/docs/game-engine/rendering', '481'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/game-engine/update',
                component: ComponentCreator('/ball-game-cpp/docs/game-engine/update', '9a0'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/install/',
                component: ComponentCreator('/ball-game-cpp/docs/install/', '51c'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/protocol',
                component: ComponentCreator('/ball-game-cpp/docs/protocol', '93c'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/server',
                component: ComponentCreator('/ball-game-cpp/docs/server', 'e07'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/server/components',
                component: ComponentCreator('/ball-game-cpp/docs/server/components', '1ec'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/server/config',
                component: ComponentCreator('/ball-game-cpp/docs/server/config', '5b0'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/server/mechanics',
                component: ComponentCreator('/ball-game-cpp/docs/server/mechanics', '0a6'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/server/network',
                component: ComponentCreator('/ball-game-cpp/docs/server/network', '821'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/ball-game-cpp/docs/server/optimizations',
                component: ComponentCreator('/ball-game-cpp/docs/server/optimizations', 'c32'),
                exact: true,
                sidebar: "tutorialSidebar"
              }
            ]
          }
        ]
      }
    ]
  },
  {
    path: '/ball-game-cpp/',
    component: ComponentCreator('/ball-game-cpp/', 'f66'),
    exact: true
  },
  {
    path: '*',
    component: ComponentCreator('*'),
  },
];

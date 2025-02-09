import React from 'react';
import ComponentCreator from '@docusaurus/ComponentCreator';

export default [
  {
    path: '/__docusaurus/debug',
    component: ComponentCreator('/__docusaurus/debug', '5ff'),
    exact: true
  },
  {
    path: '/__docusaurus/debug/config',
    component: ComponentCreator('/__docusaurus/debug/config', '5ba'),
    exact: true
  },
  {
    path: '/__docusaurus/debug/content',
    component: ComponentCreator('/__docusaurus/debug/content', 'a2b'),
    exact: true
  },
  {
    path: '/__docusaurus/debug/globalData',
    component: ComponentCreator('/__docusaurus/debug/globalData', 'c3c'),
    exact: true
  },
  {
    path: '/__docusaurus/debug/metadata',
    component: ComponentCreator('/__docusaurus/debug/metadata', '156'),
    exact: true
  },
  {
    path: '/__docusaurus/debug/registry',
    component: ComponentCreator('/__docusaurus/debug/registry', '88c'),
    exact: true
  },
  {
    path: '/__docusaurus/debug/routes',
    component: ComponentCreator('/__docusaurus/debug/routes', '000'),
    exact: true
  },
  {
    path: '/docs',
    component: ComponentCreator('/docs', '291'),
    routes: [
      {
        path: '/docs',
        component: ComponentCreator('/docs', '9ac'),
        routes: [
          {
            path: '/docs',
            component: ComponentCreator('/docs', '4df'),
            routes: [
              {
                path: '/docs/blank',
                component: ComponentCreator('/docs/blank', '5fc'),
                exact: true
              },
              {
                path: '/docs/client',
                component: ComponentCreator('/docs/client', 'f96'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/client/architecture',
                component: ComponentCreator('/docs/client/architecture', 'fad'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/client/components',
                component: ComponentCreator('/docs/client/components', 'a5d'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/client/config',
                component: ComponentCreator('/docs/client/config', '7fc'),
                exact: true
              },
              {
                path: '/docs/client/game-mechanics',
                component: ComponentCreator('/docs/client/game-mechanics', '401'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/client/network',
                component: ComponentCreator('/docs/client/network', 'e25'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/client/rendering',
                component: ComponentCreator('/docs/client/rendering', '729'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/game-engine',
                component: ComponentCreator('/docs/game-engine', '9ab'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/game-engine/architecture',
                component: ComponentCreator('/docs/game-engine/architecture', '042'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/game-engine/components',
                component: ComponentCreator('/docs/game-engine/components', '705'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/game-engine/entity',
                component: ComponentCreator('/docs/game-engine/entity', '473'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/game-engine/rendering',
                component: ComponentCreator('/docs/game-engine/rendering', 'd22'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/game-engine/update',
                component: ComponentCreator('/docs/game-engine/update', '0c7'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/install/',
                component: ComponentCreator('/docs/install/', '1a8'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/protocol',
                component: ComponentCreator('/docs/protocol', 'f9c'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/server',
                component: ComponentCreator('/docs/server', '2b6'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/server/components',
                component: ComponentCreator('/docs/server/components', '21f'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/server/config',
                component: ComponentCreator('/docs/server/config', '625'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/server/mechanics',
                component: ComponentCreator('/docs/server/mechanics', 'b9e'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/server/network',
                component: ComponentCreator('/docs/server/network', '46f'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/server/optimizations',
                component: ComponentCreator('/docs/server/optimizations', '031'),
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
    path: '/',
    component: ComponentCreator('/', '2e1'),
    exact: true
  },
  {
    path: '*',
    component: ComponentCreator('*'),
  },
];

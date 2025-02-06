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
    component: ComponentCreator('/docs', '9a1'),
    routes: [
      {
        path: '/docs',
        component: ComponentCreator('/docs', 'b47'),
        routes: [
          {
            path: '/docs',
            component: ComponentCreator('/docs', '19f'),
            routes: [
              {
                path: '/docs/blank',
                component: ComponentCreator('/docs/blank', '5fc'),
                exact: true
              },
              {
                path: '/docs/client',
                component: ComponentCreator('/docs/client', 'f42'),
                exact: true
              },
              {
                path: '/docs/game-engine',
                component: ComponentCreator('/docs/game-engine', 'fd8'),
                exact: true
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
                path: '/docs/game-engine/intro',
                component: ComponentCreator('/docs/game-engine/intro', '483'),
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
                path: '/docs/server',
                component: ComponentCreator('/docs/server', '6b7'),
                exact: true
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

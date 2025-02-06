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
    component: ComponentCreator('/docs', '6d0'),
    routes: [
      {
        path: '/docs',
        component: ComponentCreator('/docs', 'a1e'),
        routes: [
          {
            path: '/docs',
            component: ComponentCreator('/docs', '6a7'),
            routes: [
              {
                path: '/docs/blank',
                component: ComponentCreator('/docs/blank', '5fc'),
                exact: true
              },
              {
                path: '/docs/client',
                component: ComponentCreator('/docs/client', 'caa'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/game-engine',
                component: ComponentCreator('/docs/game-engine', '376'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/server',
                component: ComponentCreator('/docs/server', 'fc9'),
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

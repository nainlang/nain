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
    path: '/blog',
    component: ComponentCreator('/blog', '916'),
    exact: true
  },
  {
    path: '/blog/archive',
    component: ComponentCreator('/blog/archive', '182'),
    exact: true
  },
  {
    path: '/blog/authors',
    component: ComponentCreator('/blog/authors', '0b7'),
    exact: true
  },
  {
    path: '/blog/authors/mario',
    component: ComponentCreator('/blog/authors/mario', '26d'),
    exact: true
  },
  {
    path: '/blog/hello',
    component: ComponentCreator('/blog/hello', '3ee'),
    exact: true
  },
  {
    path: '/blog/tags',
    component: ComponentCreator('/blog/tags', '287'),
    exact: true
  },
  {
    path: '/blog/tags/hello',
    component: ComponentCreator('/blog/tags/hello', 'e3d'),
    exact: true
  },
  {
    path: '/markdown-page',
    component: ComponentCreator('/markdown-page', '3d7'),
    exact: true
  },
  {
    path: '/docs',
    component: ComponentCreator('/docs', 'bbf'),
    routes: [
      {
        path: '/docs',
        component: ComponentCreator('/docs', 'c3d'),
        routes: [
          {
            path: '/docs',
            component: ComponentCreator('/docs', '208'),
            routes: [
              {
                path: '/docs/basic-tutorial/conditionals',
                component: ComponentCreator('/docs/basic-tutorial/conditionals', 'a3c'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/basic-tutorial/functions',
                component: ComponentCreator('/docs/basic-tutorial/functions', '086'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/basic-tutorial/helloworld',
                component: ComponentCreator('/docs/basic-tutorial/helloworld', 'add'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/basic-tutorial/installation',
                component: ComponentCreator('/docs/basic-tutorial/installation', '5d4'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/basic-tutorial/vars',
                component: ComponentCreator('/docs/basic-tutorial/vars', '8db'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/extra/bestpractises',
                component: ComponentCreator('/docs/extra/bestpractises', 'f68'),
                exact: true,
                sidebar: "tutorialSidebar"
              },
              {
                path: '/docs/intro',
                component: ComponentCreator('/docs/intro', '61d'),
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

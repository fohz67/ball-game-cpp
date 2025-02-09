module.exports = {
  title: 'Ball Game Documentation',
  tagline: 'Documentation',
  url: 'http://localhost',
  baseUrl: '/ball-game-cpp/',
  onBrokenLinks: 'throw',
  onBrokenMarkdownLinks: 'warn',
  favicon: 'img/favicon.ico',
  organizationName: 'Fōhz',
  projectName: 'Ball Game Documentation',
  presets: [
    [
      'classic',
      {
        docs: {
          sidebarPath: require.resolve('./sidebars.js'),
        },
        blog: false,
        theme: {
          customCss: require.resolve('./src/css/custom.css'),
        },
      },
    ],
  ],
};

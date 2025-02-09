"use strict";(self.webpackChunkBall_Game_C_Documentation=self.webpackChunkBall_Game_C_Documentation||[]).push([[208],{1203:(e,n,t)=>{t.r(n),t.d(n,{assets:()=>o,contentTitle:()=>c,default:()=>h,frontMatter:()=>a,metadata:()=>i,toc:()=>l});const i=JSON.parse('{"id":"client/index","title":"Overview","description":"This documentation covers the Game Client architecture, including networking, rendering, user interaction, and HUD components. Below is an overview of the different sections explaining how the client operates.","source":"@site/docs/client/index.md","sourceDirName":"client","slug":"/client","permalink":"/docs/client","draft":false,"unlisted":false,"tags":[],"version":"current","frontMatter":{"title":"Overview","slug":"/client"},"sidebar":"tutorialSidebar","previous":{"title":"Configuration","permalink":"/docs/server/config"},"next":{"title":"Architecture","permalink":"/docs/client/architecture"}}');var r=t(4848),s=t(8453);const a={title:"Overview",slug:"/client"},c="Game Client Documentation",o={},l=[{value:"Key Features:",id:"key-features",level:2},{value:"Sections",id:"sections",level:2},{value:"1. Architecture",id:"1-architecture",level:3},{value:"2. Network System",id:"2-network-system",level:3},{value:"3. Game Mechanics",id:"3-game-mechanics",level:3},{value:"4. Rendering System",id:"4-rendering-system",level:3},{value:"5. HUD &amp; Components",id:"5-hud--components",level:3},{value:"6. Configuration",id:"6-configuration",level:3}];function d(e){const n={a:"a",code:"code",h1:"h1",h2:"h2",h3:"h3",header:"header",li:"li",p:"p",strong:"strong",ul:"ul",...(0,s.R)(),...e.components};return(0,r.jsxs)(r.Fragment,{children:[(0,r.jsx)(n.header,{children:(0,r.jsx)(n.h1,{id:"game-client-documentation",children:"Game Client Documentation"})}),"\n",(0,r.jsxs)(n.p,{children:["This documentation covers the ",(0,r.jsx)(n.strong,{children:"Game Client"})," architecture, including networking, rendering, user interaction, and HUD components. Below is an overview of the different sections explaining how the client operates."]}),"\n",(0,r.jsx)(n.h1,{id:"overview",children:"Overview"}),"\n",(0,r.jsx)(n.p,{children:"The Game Client is responsible for connecting to the server, rendering the game world, managing player input, and updating the game state dynamically. It efficiently handles real-time updates and ensures a smooth gameplay experience."}),"\n",(0,r.jsx)(n.h2,{id:"key-features",children:"Key Features:"}),"\n",(0,r.jsxs)(n.ul,{children:["\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.strong,{children:"Networking System"}),": Uses ",(0,r.jsx)(n.code,{children:"asio"})," to communicate with the server via TCP."]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.strong,{children:"Game Loop"}),": Manages rendering, input handling, and updates at a fixed frame rate."]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.strong,{children:"Rendering System"}),": Utilizes SFML for efficient drawing and smooth animations."]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.strong,{children:"HUD & Leaderboard"}),": Displays real-time stats and rankings dynamically."]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.strong,{children:"Entity Management"}),": Handles cell creation, deletion, and movement updates efficiently."]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.strong,{children:"Interpolation & Viewport"}),": Ensures smooth motion and adaptive camera movement."]}),"\n"]}),"\n",(0,r.jsx)(n.h2,{id:"sections",children:"Sections"}),"\n",(0,r.jsx)(n.h3,{id:"1-architecture",children:(0,r.jsx)(n.a,{href:"./client/architecture",children:"1. Architecture"})}),"\n",(0,r.jsxs)(n.p,{children:["Understand the ",(0,r.jsx)(n.strong,{children:"networked client structure"})," and its communication with the server."]}),"\n",(0,r.jsx)(n.h3,{id:"2-network-system",children:(0,r.jsx)(n.a,{href:"./client/network",children:"2. Network System"})}),"\n",(0,r.jsx)(n.p,{children:"Learn how the client connects to the server, sends/receives packets, and handles network messages."}),"\n",(0,r.jsx)(n.h3,{id:"3-game-mechanics",children:(0,r.jsx)(n.a,{href:"./client/game-mechanics",children:"3. Game Mechanics"})}),"\n",(0,r.jsxs)(n.p,{children:["Explore the ",(0,r.jsx)(n.strong,{children:"game loop"}),", input handling, interpolation, and in-game updates."]}),"\n",(0,r.jsx)(n.h3,{id:"4-rendering-system",children:(0,r.jsx)(n.a,{href:"./client/rendering",children:"4. Rendering System"})}),"\n",(0,r.jsxs)(n.p,{children:["Understand how SFML is used for ",(0,r.jsx)(n.strong,{children:"drawing cells, HUD elements, and animations"}),"."]}),"\n",(0,r.jsx)(n.h3,{id:"5-hud--components",children:(0,r.jsx)(n.a,{href:"./client/components",children:"5. HUD & Components"})}),"\n",(0,r.jsxs)(n.p,{children:["Explore the ",(0,r.jsx)(n.strong,{children:"HUD, leaderboard, chatbox, and UI elements"})," that enhance gameplay experience."]}),"\n",(0,r.jsx)(n.h3,{id:"6-configuration",children:(0,r.jsx)(n.a,{href:"./client/config",children:"6. Configuration"})}),"\n",(0,r.jsx)(n.p,{children:"Personalize your client as you like."}),"\n",(0,r.jsxs)(n.p,{children:["Each section provides in-depth explanations and structured documentation to help you understand the ",(0,r.jsx)(n.strong,{children:"Game Client"})," functionality."]})]})}function h(e={}){const{wrapper:n}={...(0,s.R)(),...e.components};return n?(0,r.jsx)(n,{...e,children:(0,r.jsx)(d,{...e})}):d(e)}},8453:(e,n,t)=>{t.d(n,{R:()=>a,x:()=>c});var i=t(6540);const r={},s=i.createContext(r);function a(e){const n=i.useContext(s);return i.useMemo((function(){return"function"==typeof e?e(n):{...n,...e}}),[n,e])}function c(e){let n;return n=e.disableParentContext?"function"==typeof e.components?e.components(r):e.components||r:a(e.components),i.createElement(s.Provider,{value:n},e.children)}}}]);
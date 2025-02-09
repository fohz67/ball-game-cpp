"use strict";(self.webpackChunkBall_Game_C_Documentation=self.webpackChunkBall_Game_C_Documentation||[]).push([[539],{3699:(e,n,t)=>{t.r(n),t.d(n,{assets:()=>d,contentTitle:()=>o,default:()=>h,frontMatter:()=>a,metadata:()=>i,toc:()=>c});const i=JSON.parse('{"id":"game-engine/index","title":"Overview","description":"This documentation covers the Game Engine architecture, including entities, components, rendering, and updates. Below is an overview of the different sections that explain how the system works.","source":"@site/docs/game-engine/index.md","sourceDirName":"game-engine","slug":"/game-engine","permalink":"/docs/game-engine","draft":false,"unlisted":false,"tags":[],"version":"current","frontMatter":{"title":"Overview","slug":"/game-engine"},"sidebar":"tutorialSidebar","previous":{"title":"Installation Guide","permalink":"/docs/install/"},"next":{"title":"Architecture","permalink":"/docs/game-engine/architecture"}}');var s=t(4848),r=t(8453);const a={title:"Overview",slug:"/game-engine"},o="Game Engine Documentation",d={},c=[{value:"Key Features:",id:"key-features",level:2},{value:"Sections",id:"sections",level:2},{value:"1. Architecture",id:"1-architecture",level:3},{value:"2. Component",id:"2-component",level:3},{value:"3. Entity",id:"3-entity",level:3},{value:"4. Rendering",id:"4-rendering",level:3},{value:"5. Update",id:"5-update",level:3}];function l(e){const n={a:"a",h1:"h1",h2:"h2",h3:"h3",header:"header",li:"li",p:"p",strong:"strong",ul:"ul",...(0,r.R)(),...e.components};return(0,s.jsxs)(s.Fragment,{children:[(0,s.jsx)(n.header,{children:(0,s.jsx)(n.h1,{id:"game-engine-documentation",children:"Game Engine Documentation"})}),"\n",(0,s.jsxs)(n.p,{children:["This documentation covers the ",(0,s.jsx)(n.strong,{children:"Game Engine"})," architecture, including entities, components, rendering, and updates. Below is an overview of the different sections that explain how the system works."]}),"\n",(0,s.jsx)(n.h1,{id:"overview",children:"Overview"}),"\n",(0,s.jsx)(n.p,{children:"The Game Engine is the core framework responsible for managing game entities, rendering, components, and updates. It provides a structured way to handle game logic efficiently."}),"\n",(0,s.jsx)(n.h2,{id:"key-features",children:"Key Features:"}),"\n",(0,s.jsxs)(n.ul,{children:["\n",(0,s.jsxs)(n.li,{children:[(0,s.jsx)(n.strong,{children:"Entity-Component System (ECS)"}),": Implements a modular design where each entity can hold multiple components."]}),"\n",(0,s.jsxs)(n.li,{children:[(0,s.jsx)(n.strong,{children:"Rendering System"}),": Uses SFML for drawing graphical elements efficiently."]}),"\n",(0,s.jsxs)(n.li,{children:[(0,s.jsx)(n.strong,{children:"Update System"}),": Processes logic updates for entities dynamically."]}),"\n",(0,s.jsxs)(n.li,{children:[(0,s.jsx)(n.strong,{children:"Component System"}),": Allows defining behaviors that can be attached or removed from entities."]}),"\n",(0,s.jsxs)(n.li,{children:[(0,s.jsx)(n.strong,{children:"Entity Management"}),": Handles creation, deletion, and linking of game objects."]}),"\n"]}),"\n",(0,s.jsx)(n.h2,{id:"sections",children:"Sections"}),"\n",(0,s.jsx)(n.h3,{id:"1-architecture",children:(0,s.jsx)(n.a,{href:"./game-engine/architecture",children:"1. Architecture"})}),"\n",(0,s.jsxs)(n.p,{children:["Understand the ",(0,s.jsx)(n.strong,{children:"Entity-Component-System (ECS)"})," model and how the Game Engine is structured."]}),"\n",(0,s.jsx)(n.h3,{id:"2-component",children:(0,s.jsx)(n.a,{href:"./game-engine/components",children:"2. Component"})}),"\n",(0,s.jsxs)(n.p,{children:["Explore how ",(0,s.jsx)(n.strong,{children:"components"})," define entity behavior, including ",(0,s.jsx)(n.strong,{children:"position, texture, and text"}),"."]}),"\n",(0,s.jsx)(n.h3,{id:"3-entity",children:(0,s.jsx)(n.a,{href:"./game-engine/entity",children:"3. Entity"})}),"\n",(0,s.jsx)(n.p,{children:"Understand how entities are created, modified, and stored dynamically."}),"\n",(0,s.jsx)(n.h3,{id:"4-rendering",children:(0,s.jsx)(n.a,{href:"./game-engine/rendering",children:"4. Rendering"})}),"\n",(0,s.jsxs)(n.p,{children:["Learn how ",(0,s.jsx)(n.strong,{children:"System::render()"})," processes entities and displays ",(0,s.jsx)(n.strong,{children:"sprites, text, and shapes"})," using SFML."]}),"\n",(0,s.jsx)(n.h3,{id:"5-update",children:(0,s.jsx)(n.a,{href:"./game-engine/update",children:"5. Update"})}),"\n",(0,s.jsxs)(n.p,{children:["Learn how the ",(0,s.jsx)(n.strong,{children:"System::update()"})," function modifies entity attributes dynamically, including ",(0,s.jsx)(n.strong,{children:"position, text, and textures"}),".\nEach section contains in-depth explanations and code examples to help you understand the ",(0,s.jsx)(n.strong,{children:"Game Engine"}),"."]})]})}function h(e={}){const{wrapper:n}={...(0,r.R)(),...e.components};return n?(0,s.jsx)(n,{...e,children:(0,s.jsx)(l,{...e})}):l(e)}},8453:(e,n,t)=>{t.d(n,{R:()=>a,x:()=>o});var i=t(6540);const s={},r=i.createContext(s);function a(e){const n=i.useContext(r);return i.useMemo((function(){return"function"==typeof e?e(n):{...n,...e}}),[n,e])}function o(e){let n;return n=e.disableParentContext?"function"==typeof e.components?e.components(s):e.components||s:a(e.components),i.createElement(r.Provider,{value:n},e.children)}}}]);
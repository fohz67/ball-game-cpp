"use strict";(self.webpackChunkBall_Game_C_Documentation=self.webpackChunkBall_Game_C_Documentation||[]).push([[381],{6047:(e,n,i)=>{i.r(n),i.d(n,{assets:()=>l,contentTitle:()=>o,default:()=>h,frontMatter:()=>d,metadata:()=>r,toc:()=>a});const r=JSON.parse('{"id":"game-engine/rendering","title":"Rendering","description":"The rendering system is responsible for drawing game objects on the screen using SFML. It processes entities that have renderable components and updates their visual state.","source":"@site/docs/game-engine/rendering.md","sourceDirName":"game-engine","slug":"/game-engine/rendering","permalink":"/docs/game-engine/rendering","draft":false,"unlisted":false,"tags":[],"version":"current","frontMatter":{"title":"Rendering","slug":"/game-engine/rendering"},"sidebar":"tutorialSidebar","previous":{"title":"Entity","permalink":"/docs/game-engine/entity"},"next":{"title":"Update","permalink":"/docs/game-engine/update"}}');var t=i(4848),s=i(8453);const d={title:"Rendering",slug:"/game-engine/rendering"},o="Rendering System",l={},a=[{value:"How Rendering Works:",id:"how-rendering-works",level:2},{value:"Rendering Pipeline:",id:"rendering-pipeline",level:2},{value:"Components Rendered:",id:"components-rendered",level:2}];function c(e){const n={code:"code",h1:"h1",h2:"h2",header:"header",li:"li",ol:"ol",p:"p",pre:"pre",strong:"strong",ul:"ul",...(0,s.R)(),...e.components};return(0,t.jsxs)(t.Fragment,{children:[(0,t.jsx)(n.header,{children:(0,t.jsx)(n.h1,{id:"rendering-system",children:"Rendering System"})}),"\n",(0,t.jsx)(n.p,{children:"The rendering system is responsible for drawing game objects on the screen using SFML. It processes entities that have renderable components and updates their visual state."}),"\n",(0,t.jsx)(n.h2,{id:"how-rendering-works",children:"How Rendering Works:"}),"\n",(0,t.jsxs)(n.ol,{children:["\n",(0,t.jsxs)(n.li,{children:["The game loop calls ",(0,t.jsx)(n.code,{children:"System::render()"}),"."]}),"\n",(0,t.jsxs)(n.li,{children:["The ",(0,t.jsx)(n.code,{children:"render()"})," function iterates over all entities."]}),"\n",(0,t.jsxs)(n.li,{children:["If an entity has a ",(0,t.jsx)(n.strong,{children:"Sprite, Text, or Shape component"}),", it is drawn to the window."]}),"\n"]}),"\n",(0,t.jsx)(n.h2,{id:"rendering-pipeline",children:"Rendering Pipeline:"}),"\n",(0,t.jsx)(n.pre,{children:(0,t.jsx)(n.code,{className:"language-cpp",children:'System system;\nstd::map<double, Entity> entities;\n\nsf::RenderWindow window(sf::VideoMode(800, 600), "Game");\n\nwhile (window.isOpen()) {\n    window.clear();\n    system.render(window, entities);\n    window.display();\n}\n'})}),"\n",(0,t.jsx)(n.h2,{id:"components-rendered",children:"Components Rendered:"}),"\n",(0,t.jsxs)(n.ul,{children:["\n",(0,t.jsxs)(n.li,{children:[(0,t.jsx)(n.strong,{children:"Sprite"}),": ",(0,t.jsx)(n.code,{children:"entity.hasComponent<Sprite>()"})]}),"\n",(0,t.jsxs)(n.li,{children:[(0,t.jsx)(n.strong,{children:"Text"}),": ",(0,t.jsx)(n.code,{children:"entity.hasComponent<Text>()"})]}),"\n",(0,t.jsxs)(n.li,{children:[(0,t.jsx)(n.strong,{children:"Shape"}),": ",(0,t.jsx)(n.code,{children:"entity.hasComponent<Shape>()"})]}),"\n"]}),"\n",(0,t.jsx)(n.p,{children:"The rendering system ensures efficient draw calls and handles transformations dynamically."})]})}function h(e={}){const{wrapper:n}={...(0,s.R)(),...e.components};return n?(0,t.jsx)(n,{...e,children:(0,t.jsx)(c,{...e})}):c(e)}},8453:(e,n,i)=>{i.d(n,{R:()=>d,x:()=>o});var r=i(6540);const t={},s=r.createContext(t);function d(e){const n=r.useContext(s);return r.useMemo((function(){return"function"==typeof e?e(n):{...n,...e}}),[n,e])}function o(e){let n;return n=e.disableParentContext?"function"==typeof e.components?e.components(t):e.components||t:d(e.components),r.createElement(s.Provider,{value:n},e.children)}}}]);
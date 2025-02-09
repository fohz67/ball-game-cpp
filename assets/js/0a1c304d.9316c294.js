"use strict";(self.webpackChunkBall_Game_C_Documentation=self.webpackChunkBall_Game_C_Documentation||[]).push([[711],{1620:(e,d,r)=>{r.r(d),r.d(d,{assets:()=>c,contentTitle:()=>t,default:()=>j,frontMatter:()=>i,metadata:()=>s,toc:()=>h});const s=JSON.parse('{"id":"client/config","title":"Configuration","description":"Cette section d\xe9crit la configuration du client utilis\xe9e pour le Ball Game. La configuration d\xe9finit les param\xe8tres du jeu, de la fen\xeatre, du r\xe9seau et de l\'interface utilisateur.","source":"@site/docs/client/config.md","sourceDirName":"client","slug":"/client/config","permalink":"/ball-game-cpp/docs/client/config","draft":false,"unlisted":false,"tags":[],"version":"current","frontMatter":{"title":"Configuration","slug":"/client/config"}}');var n=r(4848),l=r(8453);const i={title:"Configuration",slug:"/client/config"},t="Client Configuration",c={},h=[{value:"Game",id:"game",level:2},{value:"Window",id:"window",level:2},{value:"Network",id:"network",level:2},{value:"World",id:"world",level:2},{value:"Zoom",id:"zoom",level:2},{value:"Player",id:"player",level:2},{value:"Nickname",id:"nickname",level:3},{value:"Mass",id:"mass",level:3},{value:"HUD (Interface Utilisateur)",id:"hud-interface-utilisateur",level:2},{value:"Stats",id:"stats",level:3},{value:"Leaderboard",id:"leaderboard",level:3},{value:"ChatBox",id:"chatbox",level:3},{value:"Conclusion",id:"conclusion",level:2}];function x(e){const d={code:"code",h1:"h1",h2:"h2",h3:"h3",header:"header",hr:"hr",p:"p",strong:"strong",table:"table",tbody:"tbody",td:"td",th:"th",thead:"thead",tr:"tr",...(0,l.R)(),...e.components};return(0,n.jsxs)(n.Fragment,{children:[(0,n.jsx)(d.header,{children:(0,n.jsx)(d.h1,{id:"client-configuration",children:"Client Configuration"})}),"\n",(0,n.jsxs)(d.p,{children:["Cette section d\xe9crit la configuration du client utilis\xe9e pour le ",(0,n.jsx)(d.strong,{children:"Ball Game"}),". La configuration d\xe9finit les param\xe8tres du jeu, de la fen\xeatre, du r\xe9seau et de l'interface utilisateur."]}),"\n",(0,n.jsx)(d.hr,{}),"\n",(0,n.jsx)(d.h2,{id:"game",children:"Game"}),"\n",(0,n.jsxs)(d.table,{children:[(0,n.jsx)(d.thead,{children:(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.th,{children:"Param\xe8tre"}),(0,n.jsx)(d.th,{children:"Valeur"}),(0,n.jsx)(d.th,{children:"Description"})]})}),(0,n.jsxs)(d.tbody,{children:[(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"FRAME_RATE"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"144"})}),(0,n.jsx)(d.td,{children:"Nombre maximal d'images par seconde."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"CAMERA_INTERPOLATE_FACTOR"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"0.1"})}),(0,n.jsx)(d.td,{children:"Facteur d'interpolation pour la cam\xe9ra."})]})]})]}),"\n",(0,n.jsx)(d.hr,{}),"\n",(0,n.jsx)(d.h2,{id:"window",children:"Window"}),"\n",(0,n.jsxs)(d.table,{children:[(0,n.jsx)(d.thead,{children:(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.th,{children:"Param\xe8tre"}),(0,n.jsx)(d.th,{children:"Valeur"}),(0,n.jsx)(d.th,{children:"Description"})]})}),(0,n.jsxs)(d.tbody,{children:[(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"WIDTH"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"1920"})}),(0,n.jsx)(d.td,{children:"Largeur de la fen\xeatre du jeu."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"HEIGHT"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"1080"})}),(0,n.jsx)(d.td,{children:"Hauteur de la fen\xeatre du jeu."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"NAME"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:'"Ball game"'})}),(0,n.jsx)(d.td,{children:"Nom de la fen\xeatre affich\xe9e."})]})]})]}),"\n",(0,n.jsx)(d.hr,{}),"\n",(0,n.jsx)(d.h2,{id:"network",children:"Network"}),"\n",(0,n.jsxs)(d.table,{children:[(0,n.jsx)(d.thead,{children:(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.th,{children:"Param\xe8tre"}),(0,n.jsx)(d.th,{children:"Valeur"}),(0,n.jsx)(d.th,{children:"Description"})]})}),(0,n.jsxs)(d.tbody,{children:[(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"HOST"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"127.0.0.1"})}),(0,n.jsx)(d.td,{children:"Adresse IP du serveur par d\xe9faut."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"PORT"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"12345"})}),(0,n.jsx)(d.td,{children:"Port du serveur de jeu."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"MAX_SIZE"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"1024"})}),(0,n.jsx)(d.td,{children:"Taille maximale des paquets r\xe9seau."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"ENTITY_LINKING_BIAS"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"0.01"})}),(0,n.jsx)(d.td,{children:"D\xe9calage d'ID utilis\xe9 pour lier les entit\xe9s (ex: pseudo et entit\xe9 associ\xe9e)."})]})]})]}),"\n",(0,n.jsx)(d.hr,{}),"\n",(0,n.jsx)(d.h2,{id:"world",children:"World"}),"\n",(0,n.jsxs)(d.table,{children:[(0,n.jsx)(d.thead,{children:(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.th,{children:"Param\xe8tre"}),(0,n.jsx)(d.th,{children:"Valeur"}),(0,n.jsx)(d.th,{children:"Description"})]})}),(0,n.jsxs)(d.tbody,{children:[(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"ID"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"1"})}),(0,n.jsx)(d.td,{children:"ID unique de l'entit\xe9 repr\xe9sentant le monde."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"BACKGROUND_COLOR"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"{20, 20, 20, 255}"})}),(0,n.jsx)(d.td,{children:"Couleur de fond du monde."})]})]})]}),"\n",(0,n.jsx)(d.hr,{}),"\n",(0,n.jsx)(d.h2,{id:"zoom",children:"Zoom"}),"\n",(0,n.jsxs)(d.table,{children:[(0,n.jsx)(d.thead,{children:(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.th,{children:"Param\xe8tre"}),(0,n.jsx)(d.th,{children:"Valeur"}),(0,n.jsx)(d.th,{children:"Description"})]})}),(0,n.jsx)(d.tbody,{children:(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"SPEED"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"50.0"})}),(0,n.jsx)(d.td,{children:"Vitesse de zoom appliqu\xe9e lors du d\xe9filement de la souris."})]})})]}),"\n",(0,n.jsx)(d.hr,{}),"\n",(0,n.jsx)(d.h2,{id:"player",children:"Player"}),"\n",(0,n.jsx)(d.h3,{id:"nickname",children:"Nickname"}),"\n",(0,n.jsxs)(d.table,{children:[(0,n.jsx)(d.thead,{children:(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.th,{children:"Param\xe8tre"}),(0,n.jsx)(d.th,{children:"Valeur"}),(0,n.jsx)(d.th,{children:"Description"})]})}),(0,n.jsxs)(d.tbody,{children:[(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"TEXT_SIZE"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"10.0"})}),(0,n.jsx)(d.td,{children:"Taille de la police du pseudo affich\xe9 en jeu."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"FONT_FAMILY"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"Montserrat"})}),(0,n.jsx)(d.td,{children:"Famille de police utilis\xe9e pour le pseudo."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"FONT_WEIGHT"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"800"})}),(0,n.jsx)(d.td,{children:"\xc9paisseur de la police du pseudo."})]})]})]}),"\n",(0,n.jsx)(d.h3,{id:"mass",children:"Mass"}),"\n",(0,n.jsxs)(d.table,{children:[(0,n.jsx)(d.thead,{children:(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.th,{children:"Param\xe8tre"}),(0,n.jsx)(d.th,{children:"Valeur"}),(0,n.jsx)(d.th,{children:"Description"})]})}),(0,n.jsxs)(d.tbody,{children:[(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"TEXT_SIZE"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"4.0"})}),(0,n.jsx)(d.td,{children:"Taille de la police affichant la masse de la cellule."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"FONT"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"Montserrat"})}),(0,n.jsx)(d.td,{children:"Police utilis\xe9e pour la masse."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"FONT_WEIGHT"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"500"})}),(0,n.jsx)(d.td,{children:"\xc9paisseur de la police de la masse."})]})]})]}),"\n",(0,n.jsx)(d.hr,{}),"\n",(0,n.jsx)(d.h2,{id:"hud-interface-utilisateur",children:"HUD (Interface Utilisateur)"}),"\n",(0,n.jsxs)(d.table,{children:[(0,n.jsx)(d.thead,{children:(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.th,{children:"Param\xe8tre"}),(0,n.jsx)(d.th,{children:"Valeur"}),(0,n.jsx)(d.th,{children:"Description"})]})}),(0,n.jsxs)(d.tbody,{children:[(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"BACKGROUND_COLOR"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"{255, 255, 255, 25}"})}),(0,n.jsx)(d.td,{children:"Couleur de fond du HUD."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"PADDING"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"10.0"})}),(0,n.jsx)(d.td,{children:"Espacement interne du HUD."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"TEXT_PADDING"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"25.0"})}),(0,n.jsx)(d.td,{children:"Espacement entre les textes."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"FONT_FAMILY"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"Montserrat"})}),(0,n.jsx)(d.td,{children:"Police d'affichage principale du HUD."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"TEXT_COLOR"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"{255, 255, 255, 255}"})}),(0,n.jsx)(d.td,{children:"Couleur des textes affich\xe9s dans le HUD."})]})]})]}),"\n",(0,n.jsx)(d.h3,{id:"stats",children:"Stats"}),"\n",(0,n.jsxs)(d.table,{children:[(0,n.jsx)(d.thead,{children:(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.th,{children:"Param\xe8tre"}),(0,n.jsx)(d.th,{children:"Valeur"}),(0,n.jsx)(d.th,{children:"Description"})]})}),(0,n.jsxs)(d.tbody,{children:[(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"WIDTH"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"180.0"})}),(0,n.jsx)(d.td,{children:"Largeur du panneau des statistiques."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"HEIGHT"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"220.0"})}),(0,n.jsx)(d.td,{children:"Hauteur du panneau des statistiques."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"LABEL_SIZE"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"18.0"})}),(0,n.jsx)(d.td,{children:"Taille de la police des libell\xe9s."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"VALUE_SIZE"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"19.0"})}),(0,n.jsx)(d.td,{children:"Taille de la police des valeurs."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"FONT_WEIGHT_LABEL"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"500"})}),(0,n.jsx)(d.td,{children:"\xc9paisseur de la police des libell\xe9s."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"FONT_WEIGHT_VALUE"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"900"})}),(0,n.jsx)(d.td,{children:"\xc9paisseur de la police des valeurs."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"VALUE_COLOR"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"{120, 107, 242, 255}"})}),(0,n.jsx)(d.td,{children:"Couleur des valeurs affich\xe9es."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"MARGIN_TOP"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"20"})}),(0,n.jsx)(d.td,{children:"Marge sup\xe9rieure du panneau des statistiques."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"MARGIN_BETWEEN_LINES"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"40"})}),(0,n.jsx)(d.td,{children:"Marge entre les lignes des statistiques."})]})]})]}),"\n",(0,n.jsx)(d.h3,{id:"leaderboard",children:"Leaderboard"}),"\n",(0,n.jsxs)(d.table,{children:[(0,n.jsx)(d.thead,{children:(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.th,{children:"Param\xe8tre"}),(0,n.jsx)(d.th,{children:"Valeur"}),(0,n.jsx)(d.th,{children:"Description"})]})}),(0,n.jsxs)(d.tbody,{children:[(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"WIDTH"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"250.0"})}),(0,n.jsx)(d.td,{children:"Largeur du panneau du classement."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"HEIGHT"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"400.0"})}),(0,n.jsx)(d.td,{children:"Hauteur du panneau du classement."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"TITLE"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"Leaderboard"})}),(0,n.jsx)(d.td,{children:"Titre affich\xe9 en haut du classement."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"TITLE_SIZE"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"23.0"})}),(0,n.jsx)(d.td,{children:"Taille de la police du titre."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"FONT_WEIGHT_LABEL"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"900"})}),(0,n.jsx)(d.td,{children:"\xc9paisseur de la police du titre."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"FONT_WEIGHT_VALUE"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"700"})}),(0,n.jsx)(d.td,{children:"\xc9paisseur de la police des noms des joueurs."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"CONTENT_SIZE"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"18.0"})}),(0,n.jsx)(d.td,{children:"Taille de la police des entr\xe9es du classement."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"MARGIN_TOP"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"40"})}),(0,n.jsx)(d.td,{children:"Marge sup\xe9rieure du panneau du classement."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"MARGIN_BETWEEN_TITLE_AND_CONTENT"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"75"})}),(0,n.jsx)(d.td,{children:"Marge entre le titre et le contenu du classement."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"MARGIN_BETWEEN_LINES"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"30"})}),(0,n.jsx)(d.td,{children:"Marge entre les lignes du classement."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"MAX_ENTRIES"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"10"})}),(0,n.jsx)(d.td,{children:"Nombre maximal de joueurs affich\xe9s dans le classement."})]})]})]}),"\n",(0,n.jsx)(d.h3,{id:"chatbox",children:"ChatBox"}),"\n",(0,n.jsxs)(d.table,{children:[(0,n.jsx)(d.thead,{children:(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.th,{children:"Param\xe8tre"}),(0,n.jsx)(d.th,{children:"Valeur"}),(0,n.jsx)(d.th,{children:"Description"})]})}),(0,n.jsxs)(d.tbody,{children:[(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"WIDTH"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"350.0"})}),(0,n.jsx)(d.td,{children:"Largeur de la bo\xeete de chat."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"HEIGHT"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"300.0"})}),(0,n.jsx)(d.td,{children:"Hauteur de la bo\xeete de chat."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"TITLE_SIZE"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"30.0"})}),(0,n.jsx)(d.td,{children:"Taille de la police du titre de la bo\xeete de chat."})]}),(0,n.jsxs)(d.tr,{children:[(0,n.jsx)(d.td,{children:(0,n.jsx)(d.strong,{children:"CONTENT_SIZE"})}),(0,n.jsx)(d.td,{children:(0,n.jsx)(d.code,{children:"30.0"})}),(0,n.jsx)(d.td,{children:"Taille de la police du contenu du chat."})]})]})]}),"\n",(0,n.jsx)(d.hr,{}),"\n",(0,n.jsx)(d.h2,{id:"conclusion",children:"Conclusion"}),"\n",(0,n.jsx)(d.p,{children:"La configuration du client d\xe9finit tous les param\xe8tres de fonctionnement essentiels au bon affichage et \xe0 l'exp\xe9rience utilisateur du jeu. Ces param\xe8tres permettent de personnaliser l'affichage, les performances et l'exp\xe9rience de jeu."})]})}function j(e={}){const{wrapper:d}={...(0,l.R)(),...e.components};return d?(0,n.jsx)(d,{...e,children:(0,n.jsx)(x,{...e})}):x(e)}},8453:(e,d,r)=>{r.d(d,{R:()=>i,x:()=>t});var s=r(6540);const n={},l=s.createContext(n);function i(e){const d=s.useContext(l);return s.useMemo((function(){return"function"==typeof e?e(d):{...d,...e}}),[d,e])}function t(e){let d;return d=e.disableParentContext?"function"==typeof e.components?e.components(n):e.components||n:i(e.components),s.createElement(l.Provider,{value:d},e.children)}}}]);
import React from "react";
import Layout from "@theme-original/Layout";
import { useLocation } from "@docusaurus/router";

export default function CustomLayout(props) {
  const location = useLocation();
  const isGameEngine = location.pathname.startsWith("/game-engine");

  return (
    <Layout {...props}>
      {isGameEngine && (
        <nav className="game-engine-nav">
          <ul>
            <li><a href="/game-engine">Accueil</a></li>
            <li><a href="/game-engine/architecture">Architecture</a></li>
            <li><a href="/game-engine/rendering">Rendering</a></li>
            <li><a href="/game-engine/components">Components</a></li>
            <li><a href="/game-engine/entity">Entities</a></li>
            <li><a href="/game-engine/update">Update System</a></li>
          </ul>
        </nav>
      )}
      {props.children}
    </Layout>
  );
}

import React from 'react';
import Layout from '@theme/Layout';
import Link from '@docusaurus/Link';
import { useColorMode } from '@docusaurus/theme-common';

export default function Home() {
  return (
    <Layout
      title="Welcome to the Ball Game Documentation"
      description="Comprehensive documentation for the Ball Game in C++">
      <HomepageContent />
    </Layout>
  );
}

function HomepageContent() {
  const { colorMode } = useColorMode();
  const isDark = colorMode === 'dark';

  return (
    <main style={{
      padding: '4rem 2rem',
      textAlign: 'center',
      maxWidth: '1100px',
      margin: 'auto',
    }}>
      <h1 style={{
        fontSize: '2.5rem',
        fontWeight: 'bold',
        marginBottom: '1rem',
        color: isDark ? '#fff' : '#222',
      }}>
        Ball Game Documentation
      </h1>
      <p style={{
        fontSize: '1.2rem',
        color: isDark ? '#bbb' : '#555',
        maxWidth: '700px',
        margin: '0 auto 3rem',
      }}>
        A complete guide to understanding the server, client, and game engine structure.
      </p>

      <div style={{
        display: 'grid',
        gridTemplateColumns: 'repeat(auto-fit, minmax(320px, 1fr))',
        gap: '2rem',
      }}>
        <Section title="Installation" link="/docs/install" description="How to install the game." isDark={isDark} />
        <Section title="Server" link="/docs/server" description="Everything about the game's backend." isDark={isDark} />
        <Section title="Client" link="/docs/client" description="How the client interacts with the game." isDark={isDark} />
        <Section title="Game Engine" link="/docs/game-engine" description="The game's rendering and logic engine." isDark={isDark} />
        <Section title="Protocol" link="/docs/protocol" description="How the data is sent to clients" isDark={isDark} />
      </div>
    </main>
  );
}

function Section({ title, link, description, isDark }) {
  return (
    <Link to={link} style={{ textDecoration: 'none' }}>
      <div style={{
        borderRadius: '12px',
        padding: '2rem',
        backgroundColor: isDark ? '#1E1E1E' : '#f9f9f9',
        boxShadow: isDark
          ? '0 5px 15px rgba(255, 255, 255, 0.1)'
          : '0 5px 15px rgba(0, 0, 0, 0.1)',
        transition: 'transform 0.3s ease, box-shadow 0.3s ease',
        textAlign: 'left',
        cursor: 'pointer',
        border: `1px solid ${isDark ? '#444' : '#ddd'}`,
      }}
      onMouseEnter={e => {
        e.currentTarget.style.transform = 'scale(1.05)';
        e.currentTarget.style.boxShadow = isDark
          ? '0 10px 25px rgba(255, 255, 255, 0.2)'
          : '0 10px 25px rgba(0, 0, 0, 0.2)';
      }}
      onMouseLeave={e => {
        e.currentTarget.style.transform = 'scale(1)';
        e.currentTarget.style.boxShadow = isDark
          ? '0 5px 15px rgba(255, 255, 255, 0.1)'
          : '0 5px 15px rgba(0, 0, 0, 0.1)';
      }}
      >
        <h2 style={{
          fontSize: '1.8rem',
          marginBottom: '0.5rem',
          color: isDark ? '#fff' : '#222',
        }}>
          {title}
        </h2>
        <p style={{
          fontSize: '1rem',
          color: isDark ? '#bbb' : '#555',
        }}>
          {description}
        </p>
      </div>
    </Link>
  );
}

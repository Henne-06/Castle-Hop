#include "game.hpp"

Game::Game() : m_window(sf::VideoMode({1280, 720}), "Castle Hop"), m_clock{} {
  m_window.setFramerateLimit(60);
}

void Game::run() {
  while (m_window.isOpen()) {
    processEvents();
    float dt = m_clock.restart().asSeconds();

    update(dt);
    render();
  }
}

void Game::processEvents() {
  while (const std::optional event = m_window.pollEvent()) {
    if (event->is<sf::Event::Closed>())
      m_window.close();
  }
}

void Game::update(float dt) {

};

void Game::render() {
  m_window.clear(sf::Color::Black);
  m_window.display();
}
#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
  // Ein einfaches SFML-Fenster öffnen
  const unsigned int windowWidth = 800;
  const unsigned int windowHeigth = 600;
  sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeigth}),
                          "2D-Game");

  // clang-format off
  
  Player knight{{50.f,50.f,},{200.f, 150.f}};

  // clang-format on

  sf::Clock clock;

  window.setFramerateLimit(60);

  while (window.isOpen()) {
    sf::Time deltaTime = clock.restart();
    float dt = deltaTime.asSeconds();

    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
    }

    knight.update(dt, {windowWidth, windowHeigth});

    window.clear(sf::Color::Blue); // Bildschirm blau färben
    window.draw(knight);
    window.display();
  }

  return 0;
}

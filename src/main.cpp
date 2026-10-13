#include "coin.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

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

  Coin coin{{400.f, 300.f}};

  window.setFramerateLimit(60);

  sf::Font font;
  if (!font.openFromFile("assets/fonts/Roboto-VariableFont_wdth,wght.ttf")) {
    std::cout << "Font-Datei konnte nicht gefunden worden" << std::flush;
  }
  sf::Text coinText(font);
  coinText.setCharacterSize(24);
  coinText.setFillColor(sf::Color::White);
  coinText.setPosition({10.f, 10.f});
  coinText.setString(L"Münzen: 0");

  while (window.isOpen()) {
    sf::Time deltaTime = clock.restart();
    float dt = deltaTime.asSeconds();

    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
    }

    knight.update(dt, {windowWidth, windowHeigth});

    if (knight.getGlobalBounds()
            .findIntersection(coin.getGlobalBounds())
            .has_value()) {

      knight.addCoins(1);
      coinText.setString(L"Münzen: " + std::to_wstring(knight.getCoins()));
      coin.respawn({windowWidth, windowHeigth});
    }

    window.clear(sf::Color::Blue); // Bildschirm blau färben
    window.draw(knight);
    window.draw(coin);
    window.draw(coinText);
    window.display();
  }

  return 0;
}

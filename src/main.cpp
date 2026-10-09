#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
  // Ein einfaches SFML-Fenster öffnen
  const unsigned int windowWidth = 800;
  const unsigned int windowHeigth = 600;
  sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeigth}),
                          "2D-Game");

  sf::RectangleShape player;
  const float playerWidth = 50.f;
  const float playerHeigth = 50.f;
  player.setSize({playerWidth, playerHeigth});
  player.setPosition({200.f, 150.f});

  sf::Clock clock;

  window.setFramerateLimit(60);

  while (window.isOpen()) {
    sf::Time deltaTime = clock.restart();
    float dt = deltaTime.asSeconds();
    float speed = 200.f;

    sf::Vector2f moveVector{};

    sf::Vector2f playerPos = player.getPosition();

    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
      /* if (event->is<sf::Event::MouseButtonPressed>()) {
          std::cout << "Mouse Click" << std:: flush;
      }*/
      /* if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {

      }  */
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
      moveVector += {0.f, -1.f};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
      moveVector += {0.f, 1.f};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
      moveVector += {-1.f, 0.f};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
      moveVector += {1.f, 0.f};
    }

    if (moveVector != sf::Vector2f{0.f, 0.f}) {
      moveVector = moveVector.normalized();
    }

    sf::Vector2f actualMovement = moveVector * speed * dt;

    playerPos += actualMovement;

    if (playerPos.x < 0) {
      playerPos.x = 0;
    }

    if (playerPos.y < 0) {
      playerPos.y = 0;
    }

    if (playerPos.x >= windowWidth - playerWidth) {
      playerPos.x = windowWidth - playerWidth;
    }

    if (playerPos.y >= windowHeigth - playerHeigth) {
      playerPos.y = windowHeigth - playerHeigth;
    }

    player.setPosition(playerPos);

    window.clear(sf::Color::Blue); // Bildschirm blau färben
    window.draw(player);
    window.display();
  }

  return 0;
}

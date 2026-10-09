#include "player.hpp"

Player::Player(sf::Vector2f size, sf::Vector2f position)
    : sf::RectangleShape(size) {
  setPosition(position);
}

void Player::update(float dt, const sf::Vector2u &windowSize) {
  float speed = 200.f;
  sf::Vector2f playerPos = getPosition();
  sf::Vector2f moveVector{};

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

  if (playerPos.x >= windowSize.x - getSize().x) {
    playerPos.x = windowSize.x - getSize().x;
  }

  if (playerPos.y >= windowSize.y - getSize().y) {
    playerPos.y = windowSize.y - getSize().y;
  }

  setPosition(playerPos);
}
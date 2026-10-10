#include "player.hpp"

Player::Player(sf::Vector2f size, sf::Vector2f position, float speed,
               sf::Color color)
    : sf::RectangleShape(size), m_speed(speed) {
  setPosition(position);
  setFillColor(color);
}

void Player::update(float dt, const sf::Vector2u &windowSize) {
  sf::Vector2f playerPos = getPosition();
  sf::Vector2f moveVector = processInput();

  sf::Vector2f actualMovement = moveVector * m_speed * dt;
  playerPos += actualMovement;

  handleCollisions(playerPos, windowSize);
  setPosition(playerPos);
}

sf::Vector2f Player::processInput() const {
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

  return moveVector;
}

void Player::handleCollisions(sf::Vector2f &pos,
                              const sf::Vector2u &windowSize) {
  if (pos.x < 0) {
    pos.x = 0;
  }

  if (pos.y < 0) {
    pos.y = 0;
  }

  if (pos.x >= windowSize.x - getSize().x) {
    pos.x = windowSize.x - getSize().x;
  }

  if (pos.y >= windowSize.y - getSize().y) {
    pos.y = windowSize.y - getSize().y;
  }
}
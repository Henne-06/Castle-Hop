#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player : public sf::RectangleShape {
public:
  Player(sf::Vector2f size, sf::Vector2f position, float speed = 200.f,
         sf::Color color = sf::Color(128, 128, 128));

  void update(float dt, const sf::Vector2u &windowSize);

private:
  sf::Vector2f processInput() const;

  void handleCollisions(sf::Vector2f &pos, const sf::Vector2u &windowSize);

  float m_speed;
};

#endif
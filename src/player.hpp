#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player : public sf::RectangleShape {
public:
  Player(sf::Vector2f size, sf::Vector2f position);

  void update(float dt, const sf::Vector2u &windowSize);
};

#endif
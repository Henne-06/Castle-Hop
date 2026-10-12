#ifndef COIN_HPP
#define COIN_HPP

#include "item.hpp"
#include <SFML/Graphics.hpp>

class Coin : public Item {
public:
  Coin(sf::Vector2f position);
  void respawn(const sf::Vector2f &windowSize);
};

#endif
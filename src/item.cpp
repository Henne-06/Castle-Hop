#include "item.hpp"

Item::Item(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : sf::RectangleShape(size) {
  setPosition(position);
  setFillColor(color);
};

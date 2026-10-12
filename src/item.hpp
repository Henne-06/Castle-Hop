#ifndef ITEM_HPP
#define ITEM_HPP

#include <SFML/Graphics.hpp>

class Item : public sf::RectangleShape {
public:
  Item(sf::Vector2f position, sf::Vector2f size = sf::Vector2f{20.f, 20.f},
       sf::Color color = sf::Color::Yellow);

  virtual ~Item() = default;

private:
};

#endif
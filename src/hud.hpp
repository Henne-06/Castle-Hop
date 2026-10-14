#ifndef HUD_HPP
#define HUD_HPP
#include <SFML/Graphics.hpp>

class HUD {
public:
  HUD(const sf::Font &font);
  void updateCoins(unsigned int coins);
  void draw(sf::RenderWindow &window);

private:
  sf::Text text;
};

#endif
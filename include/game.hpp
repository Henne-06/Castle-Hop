#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game {
public:
  Game();
  void run();

private:
  sf::RenderWindow m_window;
  sf::Clock m_clock;

  void processEvents();
  void update(float dt);
  void render();
};

#endif
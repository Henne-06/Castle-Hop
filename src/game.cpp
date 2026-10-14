#include "game.hpp"

Game::Game()
    : window(sf::VideoMode({800, 600}), "Castle Hop"), font(), hud(font),
      player(), coin()
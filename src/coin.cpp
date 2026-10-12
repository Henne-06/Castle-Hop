#include "coin.hpp"
#include <random>

Coin::Coin(sf::Vector2f position)
    : Item(position,
           {
               15.f,
               15.f,
           },
           sf::Color::Yellow) {}

void Coin::respawn(const sf::Vector2f &windowSize) {

  static std::random_device randomDevice;
  static std::mt19937 generator(randomDevice());
  std::uniform_real_distribution<float> distributionX(0.0f, windowSize.x -
                                                                getSize().x);
  std::uniform_real_distribution<float> distributionY(0.0f, windowSize.y -
                                                                getSize().y);
  setPosition({distributionX(generator), distributionY(generator)});
}
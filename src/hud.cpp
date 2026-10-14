#include "hud.hpp"
#include <iostream>

HUD::HUD(const sf::Font &font) : text{font} {
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::White);
  text.setPosition({10.f, 10.f});
  text.setString(L"Münzen: 0");
}

void HUD::updateCoins(unsigned int coins) {
  text.setString(L"Münzen: " + std::to_wstring(coins));
}

void HUD::draw(sf::RenderWindow &window) { window.draw(text); }

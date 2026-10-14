#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "coin.hpp"
#include "hud.hpp"

class Game {
    public:
    Game();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    void run();

    private:
    sf::RenderWindow window;
    sf::Font font;
    HUD hud;
    Player player;
    Coin coin;
    sf::Clock clock;
    void processEvents();
    void render();
    void update(sf::Time dt);


};
#endif
#include <SFML/Graphics.hpp>
#include <iostream>



int main() {
    // Ein einfaches SFML-Fenster öffnen
    sf::RenderWindow window(sf::VideoMode({800, 600}), "2D-Game");

    sf::RectangleShape player;
    player.setSize({50.f, 50.f});

    window.setFramerateLimit(60);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            /* if (event->is<sf::Event::MouseButtonPressed>()) {
                std::cout << "Mouse Click" << std:: flush;
            }
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if(keyPressed->code == sf::Keyboard::Key::A) {
                    std::cout << "Key A pressed" << std::flush;
                }
            } */
            
        }


        window.clear(sf::Color::Blue); // Bildschirm blau färben
        window.draw(player);
        window.display();
    }

    return 0;
}

#include <SFML/Graphics.hpp>
#include <iostream>



int main() {
    // Ein einfaches SFML-Fenster öffnen
    sf::RenderWindow window(sf::VideoMode({800, 600}), "2D-Game");

    sf::RectangleShape player;
    player.setSize({50.f, 50.f});
    player.setPosition({200.f, 150.f});

    sf::Clock clock;

    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();
        float speed = 200.f;
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            /* if (event->is<sf::Event::MouseButtonPressed>()) {
                std::cout << "Mouse Click" << std:: flush;
            }*/
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if(keyPressed->code == sf::Keyboard::Key::W) {
                    player.move({0.f, -speed * dt});
                }
                if(keyPressed->code == sf::Keyboard::Key::S) {
                    player.move({0.f, speed * dt});
                }
                if(keyPressed->code == sf::Keyboard::Key::A) {
                    player.move({-speed * dt, 0.f});
                }
                if(keyPressed->code == sf::Keyboard::Key::D) {
                    player.move({speed * dt, 0.f});
                }

            } 
            
        }


        window.clear(sf::Color::Blue); // Bildschirm blau färben
        window.draw(player);
        window.display();
    }

    return 0;
}

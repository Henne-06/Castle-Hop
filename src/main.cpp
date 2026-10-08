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

        sf::Vector2f moveVector{};

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            /* if (event->is<sf::Event::MouseButtonPressed>()) {
                std::cout << "Mouse Click" << std:: flush;
            }*/
            /* if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {

            }  */
            
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            moveVector += {0.f, -1.f};
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            moveVector += {0.f, 1.f};
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            moveVector += {-1.f, 0.f};
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            moveVector += {1.f, 0.f};
        }

        player.move(moveVector * speed * dt);

        window.clear(sf::Color::Blue); // Bildschirm blau färben
        window.draw(player);
        window.display();
    }

    return 0;
}

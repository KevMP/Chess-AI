#include  <SFML/Graphics.hpp>
#include "ChessPieces.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Chess");
    sf::Event event;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}
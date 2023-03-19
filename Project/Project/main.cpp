#include  <SFML/Graphics.hpp>
#include "Chess.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess", sf::Style::Titlebar | sf::Style::Close);

    sf::Event event;

    sf::Texture boardTexture;
    boardTexture.loadFromFile("../../Assets/Board.png");

    sf::Sprite board(boardTexture);
    board.setScale(window.getSize().x / board.getLocalBounds().width,
        window.getSize().y / board.getLocalBounds().height);


    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(board);
        window.display();

    }

    return 0;
}

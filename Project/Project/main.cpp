#include <iostream>
#include  <SFML/Graphics.hpp>
#include "Chess.h"



void generateNewBoard();//will earase all peices and cretae a new fresh board
void drawPieces();

sf::RenderWindow window(sf::VideoMode(800, 800), "Chess", sf::Style::Titlebar | sf::Style::Close);//cant resize


int main()
{
    sf::Event event;//Used in loop

    sf::Texture boardTexture;
    boardTexture.loadFromFile("../../Assets/Board.png");

    sf::Sprite board(boardTexture);
    board.setScale(window.getSize().x / board.getLocalBounds().width,
        window.getSize().y / board.getLocalBounds().height);


    generateNewBoard();


    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(board);
        drawPieces();
        window.display();
    }

    return 0;
}

void generateNewBoard() {
    chess::Pawn* pawnTest = new chess::Pawn(false, sf::Vector2i(0,0), window);
    chess::board[5][3] = static_cast<chess::ChessPiece*>(pawnTest);

}


void drawPieces() {
    for (int x = 0; x < chess::boardDimension; x++) {
        for (int y = 0; y < chess::boardDimension; y++) {
            if (chess::board[x][y] != nullptr) {
                window.draw(chess::board[x][y]->sprite);
                chess::board[x][y]->updatePosition(x, y);  
            }
        }
    }
}

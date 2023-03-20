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
    //chess::Pawn* pawnTest = new chess::Pawn(true, sf::Vector2i(0,0), window);
    //chess::board[5][3] = static_cast<chess::ChessPiece*>(pawnTest);
    
    //delete previous
    for (int x = 0; x < chess::boardDimension; x++)
        for (int y = 0; y < chess::boardDimension; y++)
            if (chess::board[x][y] != nullptr)
                delete chess::board[x][y];


    //Create black pawns
    for (int x = 0; x < chess::boardDimension; x++) {
        chess::Pawn* blackPawn = new chess::Pawn(true, sf::Vector2i(x, 1), window);
        chess::board[x][1] = blackPawn;
    }

    //White pawns
    for (int x = 0; x < chess::boardDimension; x++) {
        chess::Pawn* whitePawn = new chess::Pawn(false, sf::Vector2i(x, 6), window);
        chess::board[x][6] = whitePawn;
    }

    //Black Rooks
    chess::Rook* leftBlackRook = new chess::Rook(true, sf::Vector2i(0, 0), window);
    chess::Rook* rightBlackRook = new chess::Rook(true, sf::Vector2i(7, 0), window);
    
    chess::board[0][0] = leftBlackRook;
    chess::board[7][0] = rightBlackRook;

    

    //White Rooks
    chess::Rook* leftWhiteRook = new chess::Rook(false, sf::Vector2i(0, 7), window);
    chess::Rook* rightWhiteRook = new chess::Rook(false, sf::Vector2i(7, 7), window);

    chess::board[0][7] = leftWhiteRook;
    chess::board[7][7] = rightWhiteRook;


    //Black bishops
    chess::Bishop* leftBlackBishop = new chess::Bishop(true, sf::Vector2i(2,0), window);
    chess::Bishop* rightBlackBishop = new chess::Bishop(true, sf::Vector2i(5, 0), window);

    chess::board[2][0] = leftBlackBishop;
    chess::board[5][0] = rightBlackBishop;


    //White bishop
    chess::Bishop* leftWhiteBishop = new chess::Bishop(false, sf::Vector2i(2, 7), window);
    chess::Bishop* rightWhiteBishop = new chess::Bishop(false, sf::Vector2i(5, 7), window);

    chess::board[2][7] = leftWhiteBishop;
    chess::board[5][7] = rightWhiteBishop;

    //Black Knights
    chess::Knight* leftBlackKnight = new chess::Knight(true, sf::Vector2i(1, 0), window);
    chess::Knight* rightBlackKnight = new chess::Knight(true, sf::Vector2i(6, 0), window);

    chess::board[1][0] = leftBlackKnight;
    chess::board[6][0] = rightBlackKnight;


    //White Knights
    chess::Knight* leftWhiteKnight = new chess::Knight(false, sf::Vector2i(1, 7), window);
    chess::Knight* rightWhiteKnight = new chess::Knight(false, sf::Vector2i(6, 7), window);

    chess::board[1][7] = leftWhiteKnight;
    chess::board[6][7] = rightWhiteKnight;

    //Black Queen
    chess::Queen* blackQueen = new chess::Queen(true, sf::Vector2i(3, 0), window);
    chess::board[3][0] = blackQueen;

    //White Queen
    chess::Queen* whiteQueen = new chess::Queen(false, sf::Vector2i(3, 7), window);
    chess::board[3][7] = whiteQueen;

    //Black King
    chess::King* blackKing = new chess::King(true, sf::Vector2i(4, 0), window);
    chess::board[4][0] = blackKing;

    //White King
    chess::King* whiteKing = new chess::King(false, sf::Vector2i(4, 7), window);
    chess::board[4][7] = whiteKing;

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

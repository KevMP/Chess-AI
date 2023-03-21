#ifndef CHESS_H
#define CHESS_H
#include "SFML/System/Vector2.hpp"


namespace chess {
    extern const int boardDimension;//8 by 8 so no need for 2 variables for x and y
    extern sf::RenderWindow window;

    class ChessPiece {//must be publicly inherited to be able to typecast
    protected:
        sf::Texture texture;
        void setSize();

    public:
        bool isBlack;
        std::string pieceName;
        sf::Sprite sprite;
        sf::Vector2i position;               

        ChessPiece(bool isBlack, sf::Vector2i position, std::string pieceName);
        void updatePosition(int xCoord, int yCoord);
        std::vector<sf::Vector2i> getPossibleMoves();//returns vector of vector2 positions
    };


    extern ChessPiece* board[8][8];

    class Pawn : public ChessPiece {
    public:
        bool hasMoved = false;

        Pawn(bool isBlack, sf::Vector2i position) : ChessPiece(isBlack, position, "Pawn") {};
        std::vector<sf::Vector2i> getPossibleMoves();
    };

    class Rook : public ChessPiece {
    public:
        Rook(bool isBlack, sf::Vector2i position) : ChessPiece(isBlack, position, "Rook") {};
    };


    class Bishop : public ChessPiece {
    public:
        Bishop(bool isBlack, sf::Vector2i position) : ChessPiece(isBlack, position, "Bishop") {};
    };


    class Knight : public ChessPiece {
    public:
        Knight(bool isBlack, sf::Vector2i position) : ChessPiece(isBlack, position, "Knight") {};
    };

    class Queen : public ChessPiece {
    public:
        Queen(bool isBlack, sf::Vector2i position) : ChessPiece(isBlack, position, "Queen") {};
    };

    class King : public ChessPiece {
    public:
        King(bool isBlack, sf::Vector2i position) : ChessPiece(isBlack, position, "King") {};
    };
}

#endif // CHESS_H

#ifndef CHESS_H
#define CHESS_H
#include "SFML/System/Vector2.hpp"


namespace chess {
    const int boardDimension = 8;//8 by 8 so no need for 2 variables for x and y


    class ChessPiece {//must be publicly inherited to be able to typecast
    protected:
        sf::Texture texture;

        void setSize(sf::RenderWindow& window) { // makes fit board square
            double scaleFactor = 1.0 / boardDimension;            
            this->sprite.setScale((window.getSize().x * scaleFactor) / this->sprite.getLocalBounds().width,
                (window.getSize().y * scaleFactor)/ this->sprite.getLocalBounds().height);
        
            
        };


    public:
        std::string pieceName = "King";
        sf::Sprite sprite;
        bool isBlack = false;
        sf::Vector2i position;        
       

        ChessPiece(bool isBlack, sf::Vector2i position, sf::RenderWindow& window, std::string pieceName) {
            std::string color = (isBlack == true) ? "Black" : "White";//bool to string

            this->pieceName = pieceName;
            this->isBlack = isBlack;
            this->texture.loadFromFile("../../Assets/" + color + this->pieceName +".png");
            this->texture.setSmooth(true);
            this->sprite.setTexture(this->texture);

            this->setSize(window);
        }


        std::vector<sf::Vector2i> getPossibleMoves() {};//returns vector of vector2 positions
        
        void updatePosition(int xCoord, int yCoord) {
            int squareSize = this->sprite.getGlobalBounds().width;
            
            int xPos = xCoord * squareSize;
            int yPos = yCoord * squareSize;

            this->position.x = xCoord;
            this->position.y = yCoord;
            this->sprite.setPosition(xPos, yPos);
        }
    };


    chess::ChessPiece* board[boardDimension][boardDimension] = {
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr}
    };




    class Pawn : public ChessPiece {
    public:
        Pawn(bool isBlack, sf::Vector2i position, sf::RenderWindow& window) : ChessPiece(isBlack, position, window, "Pawn") {};
    };



    class Rook : public ChessPiece {
    public:
        Rook(bool isBlack, sf::Vector2i position, sf::RenderWindow& window) : ChessPiece(isBlack, position, window, "Rook") {};
    };


    class Bishop : public ChessPiece {
    public:
        Bishop(bool isBlack, sf::Vector2i position, sf::RenderWindow& window) : ChessPiece(isBlack, position, window, "Bishop") {};
    };


    class Knight : public ChessPiece {
    public:
        Knight(bool isBlack, sf::Vector2i position, sf::RenderWindow& window) : ChessPiece(isBlack, position, window, "Knight") {};
    };

    class Queen : public ChessPiece {
    public:
        Queen(bool isBlack, sf::Vector2i position, sf::RenderWindow& window) : ChessPiece(isBlack, position, window, "Queen") {};
    };

    class King : public ChessPiece {
    public:
        King(bool isBlack, sf::Vector2i position, sf::RenderWindow& window) : ChessPiece(isBlack, position, window, "King") {};
    };



}

#endif // CHESS_H

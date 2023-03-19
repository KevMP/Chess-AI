#ifndef CHESS_H
#define CHESS_H
#include "SFML/System/Vector2.hpp"


namespace chess {
    const int boardDimension = 8;//8 by 8 so no need for 2 variables for x and y


    class ChessPiece {//must be publicly inherited to be able to typecast
    protected:
        sf::Texture texture;

        void setSize() {
            //this->sprite.setScale()
        };


    public:
        
        sf::Sprite sprite;
        bool isBlack = false;
        sf::Vector2i position;        
       
        std::vector<sf::Vector2i> getPossibleMoves() {};//returns vector of vector2 positions
    };


    chess::ChessPiece* board[boardDimension][boardDimension] = {
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {}
    };




    class Pawn : public ChessPiece {
    public:
        Pawn(bool isBlack, sf::Vector2i position, sf::RenderWindow& window) {
            std::string color = (isBlack == true) ? "Black" : "White";//bool to string
            
            this->isBlack = isBlack;
            this->texture.loadFromFile("../../Assets/" + color + "Pawn.png");
            this->sprite.setTexture(this->texture);
        }

    };



}

#endif // CHESS_H

#include <iostream>
#include  <SFML/Graphics.hpp>
#include "Chess.h"


const int chess::boardDimension = 8;

chess::ChessPiece* chess::board[8][8] = {
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
        {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr}
};


chess::ChessPiece::ChessPiece(bool isBlack, sf::Vector2i position, std::string pieceName) {
    std::string color = (isBlack == true) ? "Black" : "White";//bool to string

    this->pieceName = pieceName;
    this->isBlack = isBlack;
    this->texture.loadFromFile("../../Assets/" + color + this->pieceName + ".png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);

    this->setSize();
}


void chess::ChessPiece::setSize() { // makes fit board square
    double scaleFactor = 1.0 / boardDimension;
    this->sprite.setScale((chess::window.getSize().x * scaleFactor) / this->sprite.getLocalBounds().width,
        (chess::window.getSize().y * scaleFactor) / this->sprite.getLocalBounds().height);
};


void chess::ChessPiece::updatePosition(int xCoord, int yCoord) {
    int squareSize = this->sprite.getGlobalBounds().width;

    int xPos = xCoord * squareSize;
    int yPos = yCoord * squareSize;

    this->position.x = xCoord;
    this->position.y = yCoord;
    this->sprite.setPosition(xPos, yPos);
};

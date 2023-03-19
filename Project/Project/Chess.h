#ifndef CHESS_H
#define CHESS_H
#include "SFML/System/Vector2.hpp"


namespace chess {
    int boardDimension = 8;//8 by 8 so no need for 2 variables for x and y


    class ChessPiece {
    public:
        ChessPiece() {};
        ChessPiece(std::nullptr_t) {};//legit dont know why I need this but it complains if I dont do this


    };



    chess::ChessPiece board[8][8] = {
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr}
    };

    

}

#endif // CHESS_H

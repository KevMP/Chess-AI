#include "UserInput.h"
#include "Chess.h"
#include <iostream>



chess::ChessPiece* returnClickedPiece() {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(chess::window);


	for (int x = 0; x < chess::boardDimension; x++) {
		for (int y = 0; y < chess::boardDimension; y++) {
			chess::ChessPiece* currentPiece = chess::board[x][y];

			if (currentPiece) {
				sf::FloatRect bound = currentPiece->sprite.getGlobalBounds();

				if (bound.contains(mousePosition.x, mousePosition.y)) return currentPiece;
			}

		}
	}
	return nullptr;
}

void displayPiecePossibleMoves(chess::ChessPiece* piece) {
	if (!piece) return;

	std::cout << piece->position.x << ", " << piece->position.y << std::endl;
}

void chess::handleEvent(sf::Event& event) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		displayPiecePossibleMoves(returnClickedPiece());
}
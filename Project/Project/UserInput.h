#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

namespace chess{
	void handleEvent(sf::Event& event);

	std::vector<sf::Sprite> possibleMovesSprites;
}




#endif // !USER_INPUT_HH
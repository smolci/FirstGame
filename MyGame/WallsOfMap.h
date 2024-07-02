#pragma once
#include <SFML/Graphics.hpp>

#define NUM_OF_WALLS 16

class WallsOfMap
{
	sf::RectangleShape walls[NUM_OF_WALLS];
public:
	WallsOfMap();
	sf::FloatRect getGlobalBounds(int i);
	void render(sf::RenderTarget& target);
};


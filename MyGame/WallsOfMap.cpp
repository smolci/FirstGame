#include "WallsOfMap.h"

WallsOfMap::WallsOfMap()
{
	for (int i = 0; i < NUM_OF_WALLS; i++) {
		walls[i].setFillColor(sf::Color::Black);
	}

	//Don't look at this :)
	walls[0].setSize(sf::Vector2f(5.f, 292.f));
	walls[0].setPosition(sf::Vector2f(70.f, 130.f));

	walls[1].setSize(sf::Vector2f(135.f, 5.f));
	walls[1].setPosition(sf::Vector2f(70.f, 130.f));

	walls[2].setSize(sf::Vector2f(5.f, 255.f));
	walls[2].setPosition(sf::Vector2f(205.f, 130.f));

	walls[3].setSize(sf::Vector2f(235.f, 5.f));
	walls[3].setPosition(sf::Vector2f(70.f, 419.f));

	walls[4].setSize(sf::Vector2f(47.f, 5.f));
	walls[4].setPosition(sf::Vector2f(210.f, 380.f));

	walls[5].setSize(sf::Vector2f(5.f, 47.f));
	walls[5].setPosition(sf::Vector2f(300.f, 373.f));

	walls[6].setSize(sf::Vector2f(5.f, 203.f));
	walls[6].setPosition(sf::Vector2f(255.f, 182.f));

	walls[7].setSize(sf::Vector2f(408.f, 5.f));
	walls[7].setPosition(sf::Vector2f(255.f, 182.f));

	walls[8].setSize(sf::Vector2f(403.f, 5.f));
	walls[8].setPosition(sf::Vector2f(300.f, 369.f));

	walls[9].setSize(sf::Vector2f(5.f, 194.f));
	walls[9].setPosition(sf::Vector2f(698.f, 180.f));

	walls[10].setSize(sf::Vector2f(5.f, 50.f));
	walls[10].setPosition(sf::Vector2f(658.f, 137.f));

	walls[11].setSize(sf::Vector2f(51.f, 5.f));
	walls[11].setPosition(sf::Vector2f(698.f, 180.f));

	walls[12].setSize(sf::Vector2f(235.f, 5.f));
	walls[12].setPosition(sf::Vector2f(658.f, 137.f));

	walls[13].setSize(sf::Vector2f(5.f, 300.f));
	walls[13].setPosition(sf::Vector2f(889.f, 138.f));

	walls[14].setSize(sf::Vector2f(5.f, 258.f));
	walls[14].setPosition(sf::Vector2f(749.f, 180.f));

	walls[15].setSize(sf::Vector2f(140.f, 5.f));
	walls[15].setPosition(sf::Vector2f(749.f, 433.f));
}

sf::FloatRect WallsOfMap::getGlobalBounds(int i)
{
	return this->walls[i].getGlobalBounds();
}

void WallsOfMap::render(sf::RenderTarget& target)
{
	for (int i = 0; i < NUM_OF_WALLS; i++) {
		target.draw(this->walls[i]);
	}
}
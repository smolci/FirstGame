#pragma once

#include <SFML/Graphics.hpp>
#include "WallsOfMap.h"

#define NUM_OF_ENEMIES 4

class Enemies
{
private:
	sf::CircleShape enemies[NUM_OF_ENEMIES];
	sf::Vector2f movementSpeeds[NUM_OF_ENEMIES];

	void initVariables();
	void initEnemies();
public:
	Enemies();
	virtual ~Enemies();

	//Functions
	sf::FloatRect getGlobalBounds(int i);
	void updateWindowBoundsCollision(sf::FloatRect left_wall, sf::FloatRect right_wall);
	void updateMovement();
	void update (sf::FloatRect left_wall, sf::FloatRect right_wall);
	void render(sf::RenderTarget& target);
};
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
	sf::RectangleShape player;

	float movementSpeed;
	sf::Vector2f velocity;

	// Private functions
	void initVariables();
	void initShape();
public:
	//Constructors / Destructors
	Player(float x = 125.f, float y = 270.f);
	virtual  ~Player();

	// Public functions
	void handleCollisionEnemy();
	void handleCollisionWall(sf::Vector2f prevPos);
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPosition();
	void setVelocity(sf::Vector2f velocity);
	void updateInput();
	void update();
	void render(sf::RenderTarget& target);
};
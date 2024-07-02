#include "Enemies.h"



//Private functions
void Enemies::initVariables()
{
	for (int i = 0; i < NUM_OF_ENEMIES; i++) {
		this->movementSpeeds[i].x = 8.f;
		this->movementSpeeds[i].y = 0.f;
	}
}

void Enemies::initEnemies()
{
	for (int i = 0; i < NUM_OF_ENEMIES; i++) {
		this->enemies[i].setFillColor(sf::Color::Blue);
		this->enemies[i].setRadius(5.0f);
		this->enemies[i].setOutlineColor(sf::Color::Black);
		this->enemies[i].setOutlineThickness(3.0f);
	}
}

//Constructors / Destructors
Enemies::Enemies()
{
	enemies[0].setPosition(sf::Vector2f(260.f, 210.f));
	enemies[1].setPosition(sf::Vector2f(690.f, 250.f));
	enemies[2].setPosition(sf::Vector2f(260.f, 300.f));
	enemies[3].setPosition(sf::Vector2f(690.f, 345.f));

	this->initEnemies();
	this->initVariables();
}

Enemies::~Enemies()
{
}

//Public functions
sf::FloatRect Enemies::getGlobalBounds(int i)
{
	return this->enemies[i].getGlobalBounds();
}

void Enemies::updateWindowBoundsCollision(sf::FloatRect left_wall, sf::FloatRect right_wall)
{
	for (int i = 0; i < 4; i++) {
		sf::CircleShape& enemy = enemies[i];
		sf::Vector2f& movementSpeed = movementSpeeds[i];

		// Left
		if (enemy.getGlobalBounds().left <= left_wall.left + left_wall.width && movementSpeed.x < 0) {
			movementSpeed.x = -movementSpeed.x;
		}
		// Right
		if (enemy.getGlobalBounds().left + enemy.getGlobalBounds().width >= right_wall.left && movementSpeed.x > 0) {
			movementSpeed.x = -movementSpeed.x;
		}
	}
}

void Enemies::updateMovement()
{
	for (int i = 0; i < NUM_OF_ENEMIES; i++) {
		enemies[i].move(movementSpeeds[i].x, 0.f);
	}
}

void Enemies::update(sf::FloatRect left_wall, sf::FloatRect right_wall)
{
	this->updateMovement();
	
	this->updateWindowBoundsCollision(left_wall, right_wall);
}

void Enemies::render(sf::RenderTarget& target)
{
	for (int i = 0; i < NUM_OF_ENEMIES; i++) {
		target.draw(this->enemies[i]);
	}
}
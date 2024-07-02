#include "Player.h"


// Private functions
void Player::initVariables()
{
	this->movementSpeed = 3.f;
	velocity.x = 0.f;
	velocity.y = 0.f;
}

void Player::initShape()
{
	this->player.setFillColor(sf::Color::Red);
	this->player.setSize(sf::Vector2f(20.0f, 20.0f));
	this->player.setOutlineColor(sf::Color::Black);
	this->player.setOutlineThickness(3.0f);
}


//Constructors / Destructors
Player::Player(float x, float y)
{
	this->player.setPosition(x, y);

	this->initVariables();
	this->initShape();
}

Player::~Player()
{
}

// Public functions
void Player::handleCollisionEnemy()
{
	this->player.setPosition(sf::Vector2f(125.f, 270.f));
}

void Player::handleCollisionWall(sf::Vector2f prevPos)
{
	this->player.setPosition(prevPos);
}

sf::FloatRect Player::getGlobalBounds()
{
	return this->player.getGlobalBounds();
}

sf::Vector2f Player::getPosition() {
	return this->player.getPosition();
}

void Player::setVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}

void Player::updateInput()
{
	//Keyboard inputs
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		velocity.x = -movementSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		velocity.x = movementSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		velocity.y = -movementSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		velocity.y = movementSpeed;
	}
	this->player.move(velocity);
	velocity.x = 0;
	velocity.y = 0;
}

void Player::update()
{
	this->updateInput();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->player);
}
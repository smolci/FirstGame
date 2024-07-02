#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "Player.h"
#include "Enemies.h"
#include "WallsOfMap.h"

#define NUMBER_OF_WALLS 16

// Game class
class Game
{
private:
	sf::Event ev;

	//Objects
	WallsOfMap map;
	Player player;
	Enemies enemy;
	sf::RectangleShape start, finish;

	sf::Font font;
	sf::Text end;
	bool gameWon;

	bool gameRunning;

	sf::Texture texture;
	sf::Sprite back;

	//Clock
	sf::Clock clock;
	sf::Time startTime;
	sf::Time elapsedTime;
	sf::Text timer;
	float seconds;
	bool nameGot;
	float highScore;

	sf::SoundBuffer buffer;
	sf::Sound sound;

	//Private functions
	void initShapes(sf::RenderWindow& window);
public:
	//Constructors / Destructors
	Game(sf::RenderWindow& window);
	virtual ~Game();

	//Functions
	const bool isRunning() const;
	void collisionPlayer_Enemy();
	void collisionPlayer_Walls(sf::Vector2f prevPos, int i);
	void collisionPlayer_Finish();
	bool update(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
};


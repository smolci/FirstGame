#include "Game.h"

//Private functions
void Game::initShapes(sf::RenderWindow& window)
{
	//Start
	this->start.setFillColor(sf::Color(51, 255, 125));
	this->start.setSize(sf::Vector2f(135.f, 287.f));
	this->start.setPosition(sf::Vector2f(75.f, 135.f));

	//Finish
	this->finish.setFillColor(sf::Color(51, 255, 125));
	this->finish.setSize(sf::Vector2f(140.f, 295.f));
	this->finish.setPosition(sf::Vector2f(749.f, 138.f));

	//Game won
	if (!font.loadFromFile("font/Arial.ttf")) {
		std::cout << "Failed to load font!" << std::endl;
	}
	end.setFont(font);
	end.setFillColor(sf::Color::White);
	end.setOutlineColor(sf::Color::Black);
	end.setOutlineThickness(5.f);
	end.setString("      You won!!! :)\nPress Escape to quit");
	end.setPosition(sf::Vector2f(window.getSize().x / 2 - 120, window.getSize().y / 2 - 40));
	gameWon = 0;

	//Timer
	timer.setFont(font);
	timer.setFillColor(sf::Color::White);
	timer.setOutlineColor(sf::Color::Black);
	timer.setOutlineThickness(5.f);
	timer.setPosition(sf::Vector2f(10.f, 10.f));
	
	//Name
	nameGot = 0;

	//Back of game
	texture.loadFromFile("back.png");
	back.setTexture(texture);
	back.setPosition(sf::Vector2f(210.f, 140.f));

	//Player hit enemy
	if (!buffer.loadFromFile("hit.ogg")) {
		std::cout << "Can't open music file\n";
	}
}

//Constructors / Destructors
Game::Game(sf::RenderWindow& window) {
	this->initShapes(window);
	window.setFramerateLimit(60);
	gameRunning = 1;
}

Game::~Game()
{
}

//Functions
const bool Game::isRunning() const
{
	return gameRunning;
}

void Game::collisionPlayer_Enemy()
{
	for (int i = 0; i < 4; i++) {
		sf::FloatRect playerBounds = player.getGlobalBounds();
		sf::FloatRect enemyBounds = enemy.getGlobalBounds(i);
		if (playerBounds.intersects(enemyBounds))
		{
			sound.setBuffer(buffer);
			sound.setVolume(30.f);
			sound.play();
			this->player.handleCollisionEnemy();
			
		}
	}
}

//Rekurzivna funkcija
void Game::collisionPlayer_Walls(sf::Vector2f prevPos, int i)
{
	sf::FloatRect playerBounds = player.getGlobalBounds();
	sf::FloatRect wallBounds = map.getGlobalBounds(i);
	if (playerBounds.intersects(wallBounds)) {
		this->player.handleCollisionWall(prevPos);
	}
	if (i < 16) collisionPlayer_Walls(prevPos, i + 1);
}

void Game::collisionPlayer_Finish()
{
	sf::FloatRect playerBounds = player.getGlobalBounds();
	sf::FloatRect finishBounds = finish.getGlobalBounds();
	if (playerBounds.intersects(finishBounds)) {
		gameWon = 1;
	}
}

bool Game::update(sf::RenderWindow& window)
{
	//Player
	this->collisionPlayer_Enemy();
	this->collisionPlayer_Finish();
	
	//Player collision with walls and movement
	sf::Vector2f prevPosPlayer;
	prevPosPlayer = player.getPosition();
	this->player.update();
	int i = 0;
	this->collisionPlayer_Walls(prevPosPlayer, i);// <-- Rekurzivna funkcija
	
	//Enemy collision
	sf::FloatRect left_wall, right_wall;
	left_wall = map.getGlobalBounds(6);
	right_wall = map.getGlobalBounds(9);
	this->enemy.update(left_wall, right_wall);

	//Clock
	elapsedTime = clock.getElapsedTime();
	seconds = elapsedTime.asSeconds();
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(2) << seconds;
	if (!gameWon) {
		timer.setString("Time: " + stream.str());
	}

	//Window
	while (window.pollEvent(ev))
	{
		if (this->ev.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			gameRunning = false;
			return 1;
		}
	}
	return 0;
}

void Game::render(sf::RenderWindow& window)
{
	//Clear
	window.clear(sf::Color(153, 153, 255));

	//Draw objects
	window.draw(start);
	window.draw(finish);
	window.draw(back);
	this->map.render(window);
	this->enemy.render(window);
	this->player.render(window);
	window.draw(timer);

	//End of the game
	if (gameWon) 
	{ 
		window.draw(end);
		if (!nameGot) {
			//Enter name
			nameGot = 1;
			std::cout << "Enter your name: ";
			std::string name;
			std::getline(std::cin, name);

			//Save into a file scores.txt (name : time)
			std::ofstream outfile("scores.txt", std::ios_base::app);
			outfile << name << " : " << seconds << " seconds" << std::endl;
			outfile.close();

			//Highscore
			std::ifstream inFile("highscore.txt");
			inFile >> this->highScore;
			inFile.close();

			if (seconds < this->highScore) {
				this->highScore = seconds;

				std::ofstream outFile("highscore.txt");
				outFile << this->highScore << "\n" << name;
				outFile.close();
			}
		}
	}

	//Display
	window.display();
}
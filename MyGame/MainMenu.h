#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

#define MAX_NUMBER_OF_ITEMS 2

class MainMenu
{
private:
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Background shapes
	sf::Texture backTexture;
	sf::Sprite background;
	sf::RectangleShape rect;
	sf::CircleShape circle;

	bool gameRunning;

	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS], title;

	sf::Music music;

	void initVariables();
	void initWindow();
	void initShapes();
public:
	MainMenu();
	~MainMenu();
	const bool isRunning() const;
	void draw();
	void runGame();
	void render();
};
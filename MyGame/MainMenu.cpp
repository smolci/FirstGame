#include "MainMenu.h"
#include "Game.h"

//Private functions
void MainMenu::initVariables()
{
    this->window = nullptr;
    gameRunning = 0;
}

void MainMenu::initWindow() {
	this->videoMode.height = 600;
	this->videoMode.width = 1000;
	this->window = new sf::RenderWindow(this->videoMode, "World's Hardest Game", sf::Style::Titlebar | sf::Style::Close);
}

void MainMenu::initShapes() {
    if (!font.loadFromFile("font/Arial.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
    }

    //Play
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setOutlineColor(sf::Color::Black);
    menu[0].setOutlineThickness(3.0f);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(this->videoMode.width / 2 - 50, this->videoMode.height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    //Exit
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setOutlineColor(sf::Color::Black);
    menu[1].setOutlineThickness(3.0f);
    menu[1].setString("Exit");
    menu[1].setPosition(sf::Vector2f(this->videoMode.width / 2 - 50, this->videoMode.height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    //Title
    title.setFont(font);
    title.setFillColor(sf::Color::Blue);
    title.setOutlineColor(sf::Color::Black);
    title.setOutlineThickness(3.0f);
    title.setString("The world's hardest game");
    title.setPosition(sf::Vector2f(320.f, 100.f));
    

    //Background
    if (!backTexture.loadFromFile("background.png")) std::cout << "Failed to load image!\n";
    background.setTexture(backTexture);
    
    //Circle
    this->circle.setRadius(50.f);
    this->circle.setFillColor(sf::Color::Red);
    this->circle.setPosition(150.f, 170.f);
    this->circle.setOutlineThickness(5.f);
    this->circle.setOutlineColor(sf::Color::Black);

    //Rectangle
    this->rect.setSize(sf::Vector2f(100.f, 100.f));
    this->rect.setFillColor(sf::Color::Green);
    this->rect.setPosition(700.f, 350.f);
    this->rect.setOutlineThickness(5.f);
    this->rect.setOutlineColor(sf::Color::Black);

    //Background music
    if (!music.openFromFile("music.ogg")) {
        std::cout << "Can't open music file\n";
    }
    music.setVolume(40.f);
    music.play();
    music.setLoop(true);
}

//Constructors / Destructors
MainMenu::MainMenu() {
    this->initVariables();
    this->initWindow();
    this->initShapes();
}

MainMenu::~MainMenu()
{
    delete this->window;
}

const bool MainMenu::isRunning() const
{
    return this->window->isOpen();
}

//Functions
void MainMenu::draw()
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		this->window->draw(menu[i]);
	}
}

void MainMenu::runGame()
{
    Game game(*window);
    while (game.isRunning()) {
        if (game.update(*window)) break;
        game.render(*window);
    }
    gameRunning = 0;
}

void MainMenu::render()
{
    while (this->window->pollEvent(ev)) {
        switch (ev.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::MouseButtonPressed:
            if (menu[0].getGlobalBounds().contains(ev.mouseButton.x, ev.mouseButton.y)){
                runGame();
                break;
            }
            else if (menu[1].getGlobalBounds().contains(ev.mouseButton.x, ev.mouseButton.y)) {
                window->close();
                break;
            }
        case sf::Event::MouseMoved:
            //Play
            if (menu[0].getGlobalBounds().contains(ev.mouseMove.x, ev.mouseMove.y)) {
                menu[0].setFillColor(sf::Color::Cyan);
            } else {
                menu[0].setFillColor(sf::Color::White);
            }
            //Exit
            if (menu[1].getGlobalBounds().contains(ev.mouseMove.x, ev.mouseMove.y)) {
                menu[1].setFillColor(sf::Color::Cyan);
            } else {
                menu[1].setFillColor(sf::Color::White);
            }
            //Circle
            if (circle.getGlobalBounds().contains(ev.mouseMove.x, ev.mouseMove.y)) {
                circle.setFillColor(sf::Color::Yellow);
            }
            else {
                circle.setFillColor(sf::Color::Red);
            }
            //Rectangle
            if (rect.getGlobalBounds().contains(ev.mouseMove.x, ev.mouseMove.y)) {
                rect.setFillColor(sf::Color::Blue);
            }
            else {
                rect.setFillColor(sf::Color::Green);
            }
            break;
        }
    }

    

    //Clear
    this->window->clear();

    //Draw
    this->window->draw(background);
    this->window->draw(rect);
    this->window->draw(circle);
    this->window->draw(title);
    this->draw();

    //Display
    this->window->display();
}
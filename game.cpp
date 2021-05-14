#include "game.h"


//Private functions
void Game::initVariables()
{
	this->window = nullptr;
	this->startMenu = nullptr;
	this->map = nullptr;
	this->isGameStarted = false;
	tmp = false;
	
	f.loadFromFile("arial.ttf");
	t.setString("wow co tu sie wyswietla");
	t.setFont(f);
	t.setCharacterSize(30);
}

void Game::initWindow()
{
	this->videoMode.height = 900;
	this->videoMode.width = 1260;
	this->window = new sf::RenderWindow(this->videoMode, "Tower Defense", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(0);
}

void Game::initMenu()
{
	this->startMenu = new StartMenu(this->videoMode);
}

void Game::initMap()
{
	this->map = new Map(this->videoMode);
}

//Constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initMenu();
	this->initMap();
}

//Destructor
Game::~Game()
{
	delete this->window;
	delete this->startMenu;
	delete this->map;
}



//Accessors
const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

//Functions
void Game::pollEventsMenu()
{
	//Event polling in the menu
	while (this->window->pollEvent(this->ev)) {


		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			this->keyPressedMenu();
			break;

		}
	}

}

void Game::pollEventsGame()
{
	//Event polling in the game
	while (this->window->pollEvent(this->ev)) {

		sf::Mouse mouse;
	
		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::MouseButtonPressed:
			if (this->ev.key.code == sf::Mouse::Left) {
				std::cout << "lewy" << std::endl;
			}
			break;
		case sf::Event::MouseMoved:
			
			if((mouse.getPosition(*this->window).x > 90 && mouse.getPosition(*this->window).x < 180) && (mouse.getPosition(*this->window).y>90 && mouse.getPosition(*this->window).y < 180)) {
				tmp = true;
				
			}
			//std::cout << mouse.getPosition(*this->window).x << " " << mouse.getPosition(*this->window).y << std::endl;
			break;
		}
	}

}

void Game::keyPressedMenu() 
{
	switch (this->ev.key.code)
	{
	case sf::Keyboard::Up:
		this->startMenu->moveUp();
		break;

	case sf::Keyboard::Down:
		this->startMenu->moveDown();
		break;

	case sf::Keyboard::Escape:
		this->window->close();
		break;

	case sf::Keyboard::Enter:
		switch (this->startMenu->getSelectedOption())			//Function returns which option has been selected 
		{
		case 0:
			this->isGameStarted = true;
			delete this->startMenu;
			break;
		case 1:
			this->window->close();
			break;
		}
		break;
	}
}


void Game::update()
{
	if (!this->isGameStarted) {
		this->pollEventsMenu();
	}
	else {
		
		this->pollEventsGame();
	}
	
}

void Game::render()
{
	this->window->clear();
	//Draw game objects
	if (!this->isGameStarted) {
		this->startMenu->draw(*this->window);
	}
	else {
		this->map->draw(*this->window);
		
	}
	sf::Mouse mouse;
	if (tmp) {
		//std::cout << "i co tera" << std::endl;
		
		t.setPosition(mouse.getPosition(*this->window).x, mouse.getPosition(*this->window).y);
		this->window->draw(t);
		
		
		
		
	}
	
	if ((mouse.getPosition(*this->window).x < 90 || mouse.getPosition(*this->window).x > 180) || (mouse.getPosition(*this->window).y < 90 || mouse.getPosition(*this->window).y > 180)) {
		tmp = false;

	}
	this->window->display();
}

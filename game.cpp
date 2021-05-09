#include "game.h"


//Private functions
void Game::initVariables()
{
	this->window = nullptr;
	this->startMenu = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Tower Defense", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initMenu()
{
	this->startMenu = new StartMenu(this->videoMode);
}

//Constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initMenu();
}

//Destructor
Game::~Game()
{
	delete this->window;
	delete this->startMenu;
}



//Accessors
const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

//Functions
void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev)) {


		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			this->keyPressed();
			break;

		}
	}

}

void Game::keyPressed() 
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
		switch (this->startMenu->getSelectedOption())
		{
		case 0:
			std::cout << "Game has started" << std::endl;
			break;
		case 1:
			this->window->close();
			break;
		}
	}
}
void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	this->window->clear();

	//Draw game objects
	this->startMenu->draw(*this->window);

	this->window->display();
}

#include "game.h"


//Private functions
void Game::initVariables()
{
	this->window = nullptr;
	this->startMenu = nullptr;
	this->map = nullptr;
	this->shop = nullptr;
	this->isGamePaused = false;
	this->towerContainer = nullptr;
	this->waveContainer = nullptr;
	this->endMenu = nullptr;
	this->base = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 900;
	this->videoMode.width = 1260;
	this->window = new sf::RenderWindow(this->videoMode, "Tower Defense", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(75);
}

void Game::initMenu()
{
	this->startMenu = new StartMenu(this->videoMode);
}

void Game::initMap()
{
	this->map = new Map(this->videoMode);
}


void Game::initWaveContainer()
{
	this->waveContainer = new WaveContainer();
}

void Game::initTowerContainer()
{
	this->towerContainer = new TowerContainer(*this->waveContainer);
}

void Game::initShop()
{
	this->shop = new Shop(*this->window, *this->towerContainer);
}

void Game::initBase()
{
	this->base = new Base();
}

void Game::initNewGame()
{
	this->initMap();
	this->initWaveContainer();
	this->initTowerContainer();
	this->initShop();
	this->initBase();
}

void Game::initTextControls()
{
	this->font.loadFromFile("arial.ttf");
	this->controls.setFont(this->font);
	this->controls.setFillColor(sf::Color::White);
	this->controls.setOutlineColor(sf::Color::Black);
	this->controls.setOutlineThickness(2);
	this->controls.setCharacterSize(17);
	this->controls.setString("Controls: \n Enter - start wave \n Space - pause/unpause \n 1 - 1x speed \n 2 - 2x speed \n 3 - 3x speed");
	this->controls.setPosition(sf::Vector2f(1010.0f, 650.0f));
}

//Constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initMenu();
	this->initMap();
	this->initWaveContainer();
	this->initTowerContainer();
	this->initShop();
	this->initBase();
	this->initTextControls();
}

//Destructor
Game::~Game()
{
	delete this->window;
	delete this->startMenu;
	delete this->map;
	delete this->shop;
	delete this->towerContainer;
	delete this->waveContainer;
	delete this->base;
	delete this->endMenu;
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
				if (this->shop->getIsClicked() != -1) {
					this->shop->buy();
				}
				this->shop->shopClicked();

			}
			break;
		case sf::Event::MouseMoved:

			if ((mouse.getPosition(*this->window).x > 90 && mouse.getPosition(*this->window).x < 180) && (mouse.getPosition(*this->window).y > 90 && mouse.getPosition(*this->window).y < 180)) {
				tmp = true;

			}
			//std::cout << mouse.getPosition(*this->window).x << " " << mouse.getPosition(*this->window).y << std::endl;
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Space) {					//Press space to pause/unpause the game
			if (!this->isGamePaused) this->isGamePaused = true;
			else this->isGamePaused = false;
			}
			if (ev.key.code == sf::Keyboard::Enter) {					//Press enter to start the next wave
				if (!this->waveContainer->empty()) {
					this->towerContainer->nextWave();
					this->waveContainer->startNextWave();
				}
			}
			if (ev.key.code == sf::Keyboard::Num1) {					//Press 1 to 1x speed the game
				this->window->setFramerateLimit(75);
			}
			if (ev.key.code == sf::Keyboard::Num2) {					//Press 2 to 2x speed the game
				this->window->setFramerateLimit(150);
			}
			if (ev.key.code == sf::Keyboard::Num3) {					//Press 3 to 3x speed the game
				this->window->setFramerateLimit(225);
			}
			break;
		}
	}

}

void Game::keyPressedMenu() 
{
	switch (this->ev.key.code)
	{
	case sf::Keyboard::Up:
		if (this->startMenu != nullptr) {
			this->startMenu->moveUp();
		}
		else if (this->endMenu != nullptr) {
			this->endMenu->moveUp();
		}
		break;

	case sf::Keyboard::Down:
		if (this->startMenu != nullptr) {
			this->startMenu->moveDown();
		}
		else if (this->endMenu != nullptr) {
			this->endMenu->moveDown();
		}
		break;

	case sf::Keyboard::Escape:
		this->window->close();
		break;

	case sf::Keyboard::Enter:
		if (this->startMenu != nullptr) {
			switch (this->startMenu->getSelectedOption())			//Function returns which option has been selected 
			{
			case 0:
				delete this->startMenu;
				this->startMenu = nullptr;
				break;
			case 1:
				this->window->close();
				break;
			}
		}
		if (this->endMenu != nullptr) {
			switch (this->endMenu->getSelectedOption())			//Function returns which option has been selected 
			{
			case 0:
				delete this->endMenu;
				this->endMenu = nullptr;
				this->newGame();
				break;
			case 1:
				this->window->close();
				break;
			}
		}
		break;
	}
}

void Game::gameOver()
{
	if (this->waveContainer->empty()) {
		this->endMenu = new EndMenu(this->videoMode, 1);
	}
	else if (this->base->getHp() <= 0) {
		this->endMenu = new EndMenu(this->videoMode, 0);
	}

}

void Game::newGame()
{
	this->clear();
	this->initNewGame();
	this->window->setFramerateLimit(60);
}

void Game::clear()
{
	delete this->map;
	delete this->shop;
	delete this->towerContainer;
	delete this->waveContainer;
	delete this->base;
}


void Game::update()
{
	if (this->startMenu != nullptr || this->endMenu != nullptr) {
		this->pollEventsMenu();
	}
	else {
		this->pollEventsGame();
		if (!this->isGamePaused) {
			this->shop->addGold(this->waveContainer->update(*this->window, *this->base));
			this->towerContainer->update();
			this->base->update();
		}
	}
	
}

void Game::render()
{
	this->window->clear();
	this->mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*this->window));
	//Draw game objects
	if (this->startMenu != nullptr || this->endMenu != nullptr) {
		if (this->startMenu != nullptr) {
			this->startMenu->draw(*this->window);
		}
		if (this->endMenu != nullptr) {
			this->endMenu->draw(*this->window);
		}
	}
	else {
		this->gameOver();
		this->map->draw(*this->window);
		this->waveContainer->draw(*this->window);
		this->base->draw(*this->window);
		this->towerContainer->draw(*this->window);
		this->shop->drawClickedTower();
		this->shop->draw();
		this->window->draw(this->controls);
	}
	this->window->display();
}


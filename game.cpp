#include "game.h"


//Private functions
void Game::initVariables()
{
	this->window = nullptr;
	this->startMenu = nullptr;
	this->map = nullptr;
	this->shop = nullptr;
	this->isGameStarted = false;
	this->isGamePaused = false;
	this->towerContainer = nullptr;
	this->waveContainer = nullptr;
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

void Game::initShop()
{
	this->shop = new Shop(*this->window, *this->towerContainer);
}

void Game::initTowerContainer()
{
	this->towerContainer = new TowerContainer();
}

void Game::initWaveContainer()
{
	this->waveContainer = new WaveContainer();
}

//Constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initMenu();
	this->initMap();
	this->initTowerContainer();
	this->initShop();
	this->initWaveContainer();
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
			if (ev.key.code == sf::Keyboard::Space) {					//Press space to paus/unpause the game
			if (!this->isGamePaused) this->isGamePaused = true;
			else this->isGamePaused = false;
			}
			if (ev.key.code == sf::Keyboard::Enter) {					//Press enter to start the next wave
				this->waveContainer->startNextWave();
			}
			if (ev.key.code == sf::Keyboard::Num1) {					//Press 1 to slow down the game
				this->window->setFramerateLimit(150);
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
		if (!this->isGamePaused) {
			this->waveContainer->update(*this->window);
		
		}
	}
	
}

void Game::render()
{
	this->window->clear();
	this->mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*this->window));
	//Draw game objects
	
	if (!this->isGameStarted) {
		this->startMenu->draw(*this->window);

	}
	else {

		this->map->draw(*this->window);
		//circle.setPosition(enemy.getPosition().x - circle.getRadius() / 2 - 45, enemy.getPosition().y - circle.getRadius() / 2 - 45); Ustawienie range wzgledem wiezy
		
		
		this->waveContainer->draw(*this->window);
		
		/*float dx = (enemy.getPosition().x + (enemy.getGlobalBounds().width / 2)) - (circle.getPosition().x + (circle.getGlobalBounds().width / 2));
		float dy = (enemy.getPosition().y + (enemy.getGlobalBounds().height / 2)) - (circle.getPosition().y + (circle.getGlobalBounds().height / 2));
		float d = std::sqrt(dx * dx + dy * dy);
		if (d <= ((enemy.getGlobalBounds().width / 2) + circle.getGlobalBounds().width / 2)) {

			//std::cout << "dupa" << std::endl;
		}*/
		
		this->towerContainer->draw(*this->window);
		this->shop->drawClickedTower();
		this->shop->draw();
	}
	this->window->display();
}

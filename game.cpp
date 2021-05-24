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
	tmp = false;
	
	f.loadFromFile("arial.ttf");
	t.setString("wow co tu sie wyswietla");
	t.setFont(f);
	t.setCharacterSize(30);
	enemyT.loadFromFile("enemyFast.png");
	enemy.setTexture(enemyT);
	enemy.setPosition(270.0f, -90.0f);
	direction = 0;
}

void Game::initWindow()
{
	this->videoMode.height = 900;
	this->videoMode.width = 1260;
	this->window = new sf::RenderWindow(this->videoMode, "Tower Defense", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(200);
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

//Constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initMenu();
	this->initMap();
	this->initTowerContainer();
	this->initShop();
}

//Destructor
Game::~Game()
{
	delete this->window;
	delete this->startMenu;
	delete this->map;
	delete this->shop;
	delete this->towerContainer;
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
			if (ev.key.code == sf::Keyboard::Space) {
			std::cout << "sopacja" << std::endl;
			if (!this->isGamePaused) this->isGamePaused = true;
			else this->isGamePaused = false;
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
		float speed = 1.0f;
		if (!this->isGamePaused && this->isGameStarted) {
			direction = mapTiles.chooseDirection(*this->window, enemy.getPosition(), direction);
			switch (direction) {
			case 0:
				enemy.move(0, speed);
				break;
			case 1:
				enemy.move(speed, 0);
				break;
			case 2:
				enemy.move(-speed, 0);
				break;
			case 3:
				enemy.move(0, -speed);
				break;
			}


			/*
				move down enemy.move(0,speed)
				move right enemy.move(speed,0)
				move left enemy.move(-speed,0)
				move up enemy.move(0,-speed)

			*/


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
	
	
		

		//std::cout << enemy.getGlobalBounds().left<< " " << enemy.getGlobalBounds().width << std::endl;
		window->draw(enemy);

		
	
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

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "startMenu.h"
#include "mapTiles.h"
#include "map.h"
#include "shop.h"
#include "towerContainer.h"
#include "enemy.h"
#include <iostream>

/*
		Class which acts like a game engine
*/

class Game
{
	//Private variables
	sf::RenderWindow* window;
	StartMenu* startMenu;
	Map* map;
	Shop *shop;
	MapTiles mapTiles; //tmp
	int direction; //tmp
	TowerContainer* towerContainer;
	sf::Vector2f mousePositionFloat;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Text t;
	sf::Font f;
	bool isGameStarted;
	bool isGamePaused;
	bool tmp;
	Enemy* enemy;

	//Private functions
	void initVariables();
	void initWindow();
	void initMenu();
	void initMap();
	void initShop();
	void initTowerContainer();
	void initEnemy();
public:
	//Consturctors /Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool getWindowIsOpen() const;

	//Functions
	void pollEventsMenu();
	void pollEventsGame();
	void keyPressedMenu();
	void update();
	void render();
};


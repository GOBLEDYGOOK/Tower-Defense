#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "startMenu.h"
#include "waveContainer.h"
#include <iostream>
#include "shop.h"

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
	Base *base;
	WaveContainer* waveContainer;
	TowerContainer* towerContainer;
	sf::Vector2f mousePositionFloat;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Text t;
	sf::Font f;
	bool isGameStarted;
	bool isGamePaused;
	bool tmp;
	

	//Private functions
	void initVariables();
	void initWindow();
	void initMenu();
	void initMap();
	void initWaveContainer();
	void initTowerContainer();
	void initShop();
	void initBase();
	
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


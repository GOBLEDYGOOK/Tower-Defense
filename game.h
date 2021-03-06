#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "startMenu.h"
#include "endMenu.h"
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
	EndingMenu* endMenu;
	Map* map;
	Shop *shop;
	Base *base;
	WaveContainer* waveContainer;
	TowerContainer* towerContainer;
	sf::Vector2f mousePositionFloat;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Text controls;
	sf::Text wave;
	sf::Font font;
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
	void initNewGame();
	void initText();

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
	void drawWave();
	void update();
	void render();
	void gameOver();
	void newGame();
	void clear();
};


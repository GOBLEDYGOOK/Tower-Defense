#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "startMenu.h"
#include "map.h"
#include "shop.h"
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
	sf::Vector2f mousePositionFloat;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Text t;
	sf::Font f;
	bool isGameStarted;
	bool tmp;
	
	//Private functions
	void initVariables();
	void initWindow();
	void initMenu();
	void initMap();
	void initShop();
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


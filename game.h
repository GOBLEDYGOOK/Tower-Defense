#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "startMenu.h"
#include <iostream>

/*
		Class which acts like a game engine
*/

class Game
{
	//Private variables
	sf::RenderWindow* window;
	StartMenu* startMenu;
	sf::VideoMode videoMode;
	sf::Event ev;
	
	//Private functions
	void initVariables();
	void initWindow();
	void initMenu();
public:
	//Consturctors /Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool getWindowIsOpen() const;

	//Functions
	void pollEvents();
	void keyPressed();
	void update();
	void render();
};


#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
/*
		Class which acts like a game engine
*/

class Game
{
	//Private variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Private functions
	void initVariables();
	void initWindow();
public:
	//Consturctors /Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool getWindowIsOpen() const;

	//Functions
	void pollEvents();
	void update();
	void render();
};


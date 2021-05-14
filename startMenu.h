#pragma once
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_OPTIONS 2

/*
	Class of the starting menu
*/

class StartMenu{
	//Private variables
	int selectedOption;
	sf::VideoMode videoMode;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_OPTIONS];
	sf::Text title;

	//Private functions
	void initVariables(sf::VideoMode videoMode);
public:
	//Constructors /Destructors
	StartMenu(sf::VideoMode videoMode);
	virtual ~StartMenu();

	//Accessors
	int getSelectedOption();

	//Public functions
	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	
};


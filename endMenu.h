#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "windows.h"

#define MAX_NUMBER_OF_OPTIONS 2

/*
	Class of the ending menu
*/

class EndingMenu {
	//Private variables
	int selectedOption;
	sf::VideoMode videoMode;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_OPTIONS];
	sf::Text title;

	//Private functions
	void initVariables(sf::VideoMode videoMode, bool isWin);
public:
	//Constructors /Destructors
	EndingMenu(sf::VideoMode videoMode, bool isWin);
	virtual ~EndingMenu();

	//Accessors
	int getSelectedOption();

	//Public functions
	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();

};


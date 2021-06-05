#pragma once
#pragma once
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_OPTIONS 2

/*
	Class of the ending menu
*/

class EndMenu {
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
	EndMenu(sf::VideoMode videoMode, bool isWin);
	virtual ~EndMenu();

	//Accessors
	int getSelectedOption();

	//Public functions
	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();

};


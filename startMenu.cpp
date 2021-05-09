#include "startMenu.h"
#include <iostream>


//Constructors /Destructors
StartMenu::StartMenu(sf::VideoMode videoMode)
{
	initVariables(videoMode);
}

StartMenu::~StartMenu()
{
}



//Private functions
void StartMenu::initVariables(sf::VideoMode videoMode)
{
	if (!font.loadFromFile("arial.ttf")) {
		std::exit(0);	//error
	}

	this->videoMode = videoMode;
	this->selectedOption = 0;

	title.setFont(font);
	title.setFillColor(sf::Color::Green);
	title.setString("Tower Defense");
	title.setPosition(sf::Vector2f(this->videoMode.width / 2 - title.getGlobalBounds().width / 2, this->videoMode.height * 1 / 4 ));

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Start Game");
	menu[0].setPosition(sf::Vector2f(this->videoMode.width / 2 - menu[0].getGlobalBounds().width / 2, this->videoMode.height * 1 / 2));
	
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Exit Game");
	menu[1].setPosition(sf::Vector2f(this->videoMode.width / 2 - menu[1].getGlobalBounds().width / 2, this->videoMode.height * 2 / 3));
	
	
}

//Accessors
int StartMenu::getSelectedOption()
{
	return selectedOption;
}

//Public functions
void StartMenu::draw(sf::RenderWindow & window)
{
	window.draw(title);

	for (size_t i = 0; i < MAX_NUMBER_OF_OPTIONS; i++) {
		window.draw(menu[i]);
	}
}

void StartMenu::moveUp()
{
	if (selectedOption - 1 >= 0) {
		menu[selectedOption].setFillColor(sf::Color::White);
		selectedOption--;
		menu[selectedOption].setFillColor(sf::Color::Red);
	}
	else {
		menu[selectedOption].setFillColor(sf::Color::White);
		selectedOption++;
		menu[selectedOption].setFillColor(sf::Color::Red);
	}
}

void StartMenu::moveDown()
{
	if (selectedOption + 1 < MAX_NUMBER_OF_OPTIONS) {
		menu[selectedOption].setFillColor(sf::Color::White);
		selectedOption++;
		menu[selectedOption].setFillColor(sf::Color::Red);
	}
	else {
		menu[selectedOption].setFillColor(sf::Color::White);
		selectedOption--;
		menu[selectedOption].setFillColor(sf::Color::Red);
	}
}


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
	if (!this->font.loadFromFile("arial.ttf")) {
		std::exit(0);	//error
	}

	this->videoMode = videoMode;
	this->selectedOption = 0;

	this->title.setFont(font);
	this->title.setCharacterSize(60u);
	this->title.setFillColor(sf::Color::Green);
	this->title.setString("Tower Defense");
	this->title.setPosition(sf::Vector2f(this->videoMode.width / 2 - this->title.getGlobalBounds().width / 2, this->videoMode.height * 1 / 4 ));

	this->menu[0].setFont(font);
	this->menu[0].setCharacterSize(45u);
	this->menu[0].setFillColor(sf::Color::Red);
	this->menu[0].setString("Start Game");
	this->menu[0].setPosition(sf::Vector2f(this->videoMode.width / 2 - this->menu[0].getGlobalBounds().width / 2, this->videoMode.height * 1 / 2));
	
	this->menu[1].setFont(font);
	this->menu[1].setCharacterSize(45u);
	this->menu[1].setFillColor(sf::Color::White);
	this->menu[1].setString("Exit Game");
	this->menu[1].setPosition(sf::Vector2f(this->videoMode.width / 2 - this->menu[1].getGlobalBounds().width / 2, this->videoMode.height * 2 / 3));
	
	
}

//Accessors
int StartMenu::getSelectedOption()
{
	return this->selectedOption;
}

//Public functions
void StartMenu::draw(sf::RenderWindow & window)
{
	window.draw(this->title);
	for (size_t i = 0; i < MAX_NUMBER_OF_OPTIONS; i++) {
		window.draw(this->menu[i]);
	}
}

void StartMenu::moveUp()
{
	if (this->selectedOption - 1 >= 0) {
		this->menu[this->selectedOption].setFillColor(sf::Color::White);
		this->selectedOption--;
		this->menu[this->selectedOption].setFillColor(sf::Color::Red);
	}
	else {
		this->menu[this->selectedOption].setFillColor(sf::Color::White);
		this->selectedOption++;
		this->menu[this->selectedOption].setFillColor(sf::Color::Red);
	}
}

void StartMenu::moveDown()
{
	if (this->selectedOption + 1 < MAX_NUMBER_OF_OPTIONS) {
		this->menu[this->selectedOption].setFillColor(sf::Color::White);
		this->selectedOption++;
		this->menu[this->selectedOption].setFillColor(sf::Color::Red);
	}
	else {
		this->menu[this->selectedOption].setFillColor(sf::Color::White);
		this->selectedOption--;
		this->menu[this->selectedOption].setFillColor(sf::Color::Red);
	}
}


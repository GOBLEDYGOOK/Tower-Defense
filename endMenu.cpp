#include "endMenu.h"
//Constructors /Destructors
EndingMenu::EndingMenu(sf::VideoMode videoMode, bool isWin)
{
	this->initVariables(videoMode, isWin);
}

EndingMenu::~EndingMenu()
{
}



//Private functions
void EndingMenu::initVariables(sf::VideoMode videoMode, bool isWin)
{
	if (!this->font.loadFromFile("arial.ttf"))
	{
		MessageBox(0, "Error! arial.ttf doesnt exist", 0, 0);
		exit(0);
	}

	this->videoMode = videoMode;
	this->selectedOption = 0;

	this->title.setFont(font);
	this->title.setCharacterSize(60u);
	this->title.setFillColor(sf::Color::Green);
	if (isWin == true) {
		this->title.setString("Victory!");
	}
	else this->title.setString("Defeat!");
	this->title.setPosition(sf::Vector2f(this->videoMode.width / 2 - this->title.getGlobalBounds().width / 2, this->videoMode.height * 1 / 4));

	this->menu[0].setFont(font);
	this->menu[0].setCharacterSize(45u);
	this->menu[0].setFillColor(sf::Color::Red);
	this->menu[0].setString("Try again");
	this->menu[0].setPosition(sf::Vector2f(this->videoMode.width / 2 - this->menu[0].getGlobalBounds().width / 2, this->videoMode.height * 1 / 2));

	this->menu[1].setFont(font);
	this->menu[1].setCharacterSize(45u);
	this->menu[1].setFillColor(sf::Color::White);
	this->menu[1].setString("Exit Game");
	this->menu[1].setPosition(sf::Vector2f(this->videoMode.width / 2 - this->menu[1].getGlobalBounds().width / 2, this->videoMode.height * 2 / 3));


}

//Accessors
int EndingMenu::getSelectedOption()
{
	return this->selectedOption;
}

//Public functions
void EndingMenu::draw(sf::RenderWindow & window)
{
	window.draw(this->title);
	for (size_t i = 0; i < MAX_NUMBER_OF_OPTIONS; i++) {
		window.draw(this->menu[i]);
	}
}

void EndingMenu::moveUp()
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

void EndingMenu::moveDown()
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


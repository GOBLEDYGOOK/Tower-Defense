#include "dynamicText.h"

//Private functions
void DynamicText::initVariables()
{
	this->font.loadFromFile("arial.ttf");
	this->text.setFont(this->font);
	this->text.setCharacterSize(15);
	this->text.setFillColor(sf::Color::Black);
	this->textStats.setFont(this->font);
	this->textStats.setCharacterSize(15);
	this->textStats.setFillColor(sf::Color::Green);
	this->textStats.setOutlineColor(sf::Color::Black);
	this->textStats.setOutlineThickness(1);
	this->box.setFillColor(sf::Color(200, 200, 200, 255));
	this->box.setOutlineColor(sf::Color::Black);
	this->box.setOutlineThickness(2);
	this->box.setSize(sf::Vector2f(150.0f, 75.0f));
}

//Constructor
DynamicText::DynamicText()
{
	this->initVariables();
}

//Destructor
DynamicText::~DynamicText()
{
}

//Public functions
void DynamicText::setText(std::string* tower)
{
	this->text.setString("Level: \n"
		"Damage: \n" 
		"Range:  \n");
	this->textStats.setString("                 " + tower[0] + "\n" +
		"                 " + tower[1] + "\n" +
		"                 " + tower[2]);
	
}

void DynamicText::draw(sf::RenderWindow & window)
{
	window.draw(this->box);
	window.draw(this->textStats);
	window.draw(this->text);
}

void DynamicText::setPosition(sf::Vector2f position)
{
	if (position.y == 0 && position.x == 900) {
		this->box.setPosition(sf::Vector2f(position.x - 60, position.y + 75));
		this->textStats.setPosition(sf::Vector2f(position.x - 55, position.y + 80));
		this->text.setPosition(sf::Vector2f(position.x - 55, position.y + 80));
	}
	else if (position.x == 900) {
		this->box.setPosition(sf::Vector2f(position.x - 60, position.y - 75));
		this->textStats.setPosition(sf::Vector2f(position.x - 55, position.y - 70));
		this->text.setPosition(sf::Vector2f(position.x - 55, position.y - 70));
	}
	else if (position.y == 0) {
		this->box.setPosition(sf::Vector2f(position.x, position.y + 75));
		this->textStats.setPosition(sf::Vector2f(position.x + 5, position.y + 80));
		this->text.setPosition(sf::Vector2f(position.x + 5, position.y + 80));
	}
	else {
		this->box.setPosition(sf::Vector2f(position.x, position.y - 75));
		this->textStats.setPosition(sf::Vector2f(position.x + 5, position.y - 70));
		this->text.setPosition(sf::Vector2f(position.x + 5, position.y - 70));
	}
	
}

#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "windows.h"

class DynamicText
{
	//Private variables
	sf::Font font;
	sf::Text text;
	sf::Text textStats;
	sf::RectangleShape box;

	//Private functions
	void initVariables();
public:
	//Consturctors /Destructors
	DynamicText();
	~DynamicText();

	//Public functions
	void setText(std::string* tower);
	void draw(sf::RenderWindow& window);
	void setPosition(sf::Vector2f position);
};


#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "windows.h"

class UpgradeButton
{
	//Private variables
	sf::Font font;
	sf::Text upgradeCost;
	sf::Texture buttonTexture;
	sf::Sprite buttonSprite;

	//Private funcions
	void initVariables();
public:
	//Constructors /Destructors
	UpgradeButton();
	~UpgradeButton();

	//Accessors
	sf::Sprite getButtonSprite()const;
	//Public functions
	void update();
	void draw(sf::RenderWindow &window);
	void setCost(int cost);
	void setPosition(sf::Vector2f position);
	bool contains(sf::Vector2f mousePoisition);
};


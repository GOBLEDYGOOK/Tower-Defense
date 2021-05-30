#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "towerBasic.h"
#include <iostream>

class TowerContainer
{
	//Private variables
	std::vector <Tower*> towerContainer;

	//Private functions

public:
	//Constructors /Destructors
	TowerContainer();
	~TowerContainer();

	//Public functions
	void add(sf::Vector2f mousePos, int i);
	void draw(sf::RenderWindow &window);
	
};


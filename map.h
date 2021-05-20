#pragma once
#include <SFML/Graphics.hpp>
#include "mapTiles.h"
#include <iostream>
#include <cmath>
#include <map>

class Map{
	//Private variables
	sf::Sprite map;
	sf::VideoMode videoMode;
	sf::Texture mapTexture;
	
	sf::Texture enemyT;
	sf::Sprite enemy;

	//Private functions
	void initVariables(sf::VideoMode videoMode);
	void initMap();
public:
	//Constructors /Destructors
	Map(sf::VideoMode videoMode);
	Map();
	~Map();

	//Accessors

	//Public functions
	void draw(sf::RenderWindow& window);
};


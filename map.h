#pragma once
#include <SFML/Graphics.hpp>
#include "mapTiles.h"
#include <iostream>
#include <cmath>
#include <map>
#include "windows.h"

class Map{
	//Private variables
	sf::Sprite map;
	sf::VideoMode videoMode;
	sf::Texture mapTexture;

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


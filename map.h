#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <map>

class Map{
	//Private variables
	sf::Sprite map;
	sf::VideoMode videoMode;
	sf::Texture mapTexture;
	int **isValid;
	
	sf::Texture enemyT;
	sf::Sprite enemy;

	//Private functions
	void initVariables(sf::VideoMode videoMode);
	void initMap();
public:
	//Constructors /Destructors
	Map(sf::VideoMode videoMode);
	~Map();

	//Accessors

	//Public functions
	void draw(sf::RenderWindow& window);
};


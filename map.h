#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class Map{
	//Private variables
	sf::Sprite map;
	sf::VideoMode videoMode;
	sf::Texture mapTexture;
	sf::Texture enemyT;
	sf::Sprite enemy;

	//Private functions
	void initVariables(sf::VideoMode videoMode);
public:
	//Constructors /Destructors
	Map(sf::VideoMode videoMode);
	~Map();

	//Accessors

	//Public functions
	void draw(sf::RenderWindow& window);
};


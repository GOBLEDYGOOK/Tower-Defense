#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class MapTiles
{
	//Private variables
	const static size_t height = 10;
	const static size_t width = 14;
	
	int *mapTiles;

	//Private functions
	void initVariables();
	void initTiles();
public:
	//Constructors /Destructors
	MapTiles();
	~MapTiles();

	//Accessors
	size_t getHeight()const;
	size_t getWidth()const;

	//Public functions
	bool isValid(sf::RenderWindow& window, sf::Vector2f mousePositionFloat);
	bool isTower(sf::RenderWindow& window, sf::Vector2f mousePositionFloat);
	int chooseDirection(sf::RenderWindow& window, sf::Vector2f enemyPos, int previousDirection);
};


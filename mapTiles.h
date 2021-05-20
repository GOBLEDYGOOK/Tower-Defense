#pragma once
#include <SFML/Graphics.hpp>

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


	//Public functions
	bool isValid(sf::RenderWindow& window, sf::Vector2f mousePositionFloat);
	//function which takes window, mouseposition ,
};


#include "map.h"

//Constructors /Destructors
Map::Map(sf::VideoMode videoMode)
{
	this->initVariables(videoMode);
}

Map::Map()
{
	;
}

Map::~Map()
{
}



//Private functions
void Map::initVariables(sf::VideoMode videoMode)
{
	
	if (!this->mapTexture.loadFromFile("map.png"))
	{
		MessageBox(0, "Error! map.png doesnt exist", 0, 0);
		exit(0);
	}
	this->map.setTexture(this->mapTexture);
	this->videoMode = videoMode;
	
}

void Map::initMap()
{
	
}

//Public functions
void Map::draw(sf::RenderWindow& window)
{
	window.draw(this->map);
	
}



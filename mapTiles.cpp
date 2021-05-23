#include "mapTiles.h"

void MapTiles::initVariables()
{
	this->mapTiles = nullptr;
	

}

//Private functions
void MapTiles::initTiles()
{
	this->mapTiles = new int[this->height*this->width]{
		1,1,1,0,1,1,1,1,1,1,1,0,0,0,
		1,1,1,0,1,1,1,1,1,1,1,0,0,0,
		1,1,1,0,1,1,1,1,1,1,1,0,0,0,
		1,1,1,0,0,0,0,0,0,0,1,0,0,0,
		1,1,1,1,1,1,1,1,1,0,1,0,0,0,
		1,1,1,1,1,0,0,0,0,0,1,0,0,0,
		1,1,1,1,1,0,1,1,1,1,1,0,0,0,
		1,1,1,1,1,0,0,1,1,1,1,0,0,0,
		1,1,1,1,1,1,0,1,1,1,1,0,0,0,
		1,1,1,1,1,1,0,1,1,1,1,0,0,0,
	};
	
}

//Constructor
MapTiles::MapTiles()
{
	this->initVariables();
	this->initTiles();
}

//Destructor
MapTiles::~MapTiles()
{
	delete[] this->mapTiles;
}

bool MapTiles::isValid(sf::RenderWindow & window, sf::Vector2f mousePositionFloat)
{
	/*
		Function checks if tower can be placed on the clicked tile.
	*/
	unsigned int tileSize = window.getSize().x / this->width;										
	int x = mousePositionFloat.x / tileSize;
	int y = mousePositionFloat.y / tileSize;

	if (this->mapTiles[x + (y*this->width)] == 1) {
		this->mapTiles[x + (y*this->width)] = 0;
		return true;								//Tower can be placed, return true
	}
	else return false;								//Tower can't be placed, return false
	
}

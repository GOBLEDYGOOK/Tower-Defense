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

//Accessors
size_t MapTiles::getHeight() const
{
	return this->height;
}
size_t MapTiles::getWidth() const
{
	return this->width;
}

//Public Functions
bool MapTiles::isValid(sf::RenderWindow & window, sf::Vector2f mousePositionFloat)
{
	/*
		Function checks if tower can be placed on the clicked tile.
	*/
	unsigned int tileSize = window.getSize().x / this->width;										
	int x = mousePositionFloat.x / tileSize;
	int y = mousePositionFloat.y / tileSize;

	if (this->mapTiles[x + (y*this->width)] == 1) {
		this->mapTiles[x + (y*this->width)] = -1;
		return true;								//Tower can be placed, return true
	}
	else return false;								//Tower can't be placed, return false
	
}

bool MapTiles::isTower(sf::RenderWindow & window, sf::Vector2f mousePositionFloat)
{
	unsigned int tileSize = window.getSize().x / this->width;
	int x = mousePositionFloat.x / tileSize;
	int y = mousePositionFloat.y / tileSize;

	if (this->mapTiles[x + (y*this->width)] == -1) {
		return true;								
	}
	else return false;
}

int MapTiles::chooseDirection(sf::RenderWindow & window, sf::Vector2f enemyPos, int previousDirection)
{
	/*
		return 0 - move down,
		return 1 - move right,
		return 2 - move left,
		return 3 - move up
	*/
	

	unsigned int tileSize = window.getSize().x / this->width;
	unsigned int x = enemyPos.x / tileSize;
	unsigned int y = enemyPos.y / tileSize;
	float x_ = enemyPos.x / tileSize;
	float y_ = enemyPos.y / tileSize;


	if (previousDirection == 0 && x_ == x && y_ == y) {
		if (this->mapTiles[x + (y*this->width) + 1] == 0) {
			return 1;
		}

		if (this->mapTiles[x + (y*this->width) - 1] == 0) {
			return 2;
		}	
	}
	if (previousDirection == 1 && x_ == x && y_ == y) {
		if (this->mapTiles[x + (y*this->width) + this->width] == 0) {
			return 0;
		}
		if (this->mapTiles[x + (y*this->width) - this->width] == 0) {
			return 3;
		}
		
	}
	if (previousDirection == 2 && x_ == x && y_ == y) {
		if (this->mapTiles[x + (y*this->width) + this->width] == 0) {
			return 0;
		}
		if (this->mapTiles[x + (y*this->width) - this->width] == 0) {
			return 3;
		}
		
	}
	if (this->mapTiles[x + (y*this->width)] == 0) {
		return previousDirection;
	}
	
}

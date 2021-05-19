#include "shopTowers.h"
//Constructor
ShopTowers::ShopTowers()
{
	this->initVariables();
}

//Destructor
ShopTowers::~ShopTowers()
{
}

//Private functions
void ShopTowers::initVariables()
{
	this->isClicked = -1;
	this->towers[0] = new TowerBasic();
	this->costs[0] = this->towers[0]->getCost();
	this->textureTowers[0] = this->towers[0]->getTexture();
	this->spriteTowers[0].setPosition(1020, 330);
	this->spriteTowers[0].setTexture(this->textureTowers[0]);
	
}



sf::Sprite ShopTowers::getSpriteTower(size_t i) const
{
	return spriteTowers[0];
}

int ShopTowers::getCost(size_t i) const
{
	return costs[i];
}

Tower* ShopTowers::getTower(size_t i) const
{
	return towers[i];
}


const int ShopTowers::getNumberOfTowers() const
{
	return this->numberOfTowers;
}

int ShopTowers::getIsClicked() const
{
	return this->isClicked;
}


//Public functions
void ShopTowers::changeIsClicked(int i)
{
	this->isClicked = i;
	
}
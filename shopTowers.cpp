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
	this->towers[0] = new TowerBasic();
	this->costs[0] = this->towers[0]->getCost();
	this->textureTowers[0] = this->towers[0]->getTexture();
	this->spriteTowers[0].setPosition(1020, 330);
	this->spriteTowers[0].setTexture(this->textureTowers[0]);
	this->isClicked[0] = false;
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

bool ShopTowers::getIsClicked(size_t i)
{
	return isClicked[0];
}


//Public functions
void ShopTowers::changeIsClicked(size_t i)
{
	isClicked[0] = true;
}
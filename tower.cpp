#include "tower.h"

//Constructors /Destructors
Tower::Tower()
{
	;
}

Tower::~Tower()
{
	;
}

//Accessors
int Tower::retDmg() const
{
	return this->dmg;
}

int Tower::retCost() const
{
	return this->cost;
}

int Tower::retRange() const
{
	return this->range;
}

int Tower::retLevel() const
{
	return this->level;
}

int Tower::retMaxLevel() const
{
	return this->maxLevel;
}

sf::Sprite Tower::retTexture() const
{
	return this->texture;
}

sf::Vector2i Tower::retTowerPos() const
{ 
	return this->towerPos;
}



//public functions
void Tower::levelUp()
{
	if (this->retLevel() <= this->retMaxLevel()) {
		this->level++;

	}
	
}

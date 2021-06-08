#include "tower.h"

//Constructors /Destructors
Tower::Tower(WaveContainer& waveContainer, int radius, std::string path, int cost, int dmg)
{
	this->waveContainer = &waveContainer;
	this->initVariables(cost, dmg);
	this->initTexture(path);
	this->initRange(radius);
	this->nextWave();
}

Tower::Tower(int radius, std::string path, int cost, int dmg)
{
	this->initVariables(cost, dmg);
	this->initTexture(path);
	this->initRange(radius);
	
}
Tower::~Tower()
{
	;

}void Tower::initVariables(int cost, int dmg)
{
	this->level = 1;
	this->cost = cost;
	this->dmg = dmg;
}

void Tower::initTexture(std::string path)
{
	this->towerTexture.loadFromFile(path);
	this->towerSprite.setTexture(this->towerTexture);

}

void Tower::initRange(int radius)
{
	this->range.setRadius(radius);
	this->range.setOutlineThickness(3);
	this->range.setOutlineColor(sf::Color::Color(0, 0, 255, 100));
	this->range.setFillColor(sf::Color::Color(0, 0, 255, 50));
}


Wave* Tower::getWave() const
{
	return this->wave;
}

//Accessors
int Tower::getMaxLevel() const
{
	return this->maxLevel;
}
int Tower::getDmg() const
{
	return this->dmg;
}

int Tower::getCost() const
{
	return this->cost;
}

sf::CircleShape Tower::getRange() const
{
	return this->range;
}

int Tower::getLevel() const
{
	return this->level;
}

sf::Sprite Tower::getSprite() const
{
	return this->towerSprite;
}

sf::Texture Tower::getTexture() const
{
	return this->towerTexture;
}

WaveContainer* Tower::getWaveContainer() const
{
	return this->waveContainer;
}

sf::Vector2f Tower::getCenter() const
{
	return sf::Vector2f(this->towerSprite.getPosition().x + 45, this->towerSprite.getPosition().y + 45);
}

//public functions
void Tower::setPosition(sf::Vector2f position)
{
	this->towerSprite.setPosition(position);
	this->range.setPosition(this->towerSprite.getPosition().x - this->range.getRadius() / 2 - 45, this->towerSprite.getPosition().y - this->range.getRadius() / 2 - 45);
}

void Tower::nextWave()
{
	if (!this->waveContainer->empty()) this->wave = this->waveContainer->front();
}



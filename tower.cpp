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
	this->isReady = 90;
	this->target = nullptr;
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


//Accessors
int Tower::retMaxLevel() const
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

sf::Vector2i Tower::getTowerPos() const
{
	return this->towerPos;
}

//public functions
void Tower::setPosition(sf::Vector2f position)
{
	this->towerSprite.setPosition(position);
	this->range.setPosition(this->towerSprite.getPosition().x - this->range.getRadius() / 2 - 45, this->towerSprite.getPosition().y - this->range.getRadius() / 2 - 45);
}

void Tower::shoot()
{
	if (this->isReady == 90 && this->target != nullptr) {
		this->target->receiveDamage(this->dmg);
		this->isReady = 0;
	}
	if (this->isReady < 90) {
		this->isReady++;
	}
	
	
}

void Tower::nextWave()
{
	this->wave = this->waveContainer->front();
}

void Tower::update()
{
	
	if (this->target == nullptr) {
		for (auto itr = this->wave->begin(); itr != this->wave->end(); itr++) {
			this->dx = ((*itr)->getEnemySprite().getPosition().x + ((*itr)->getEnemySprite().getGlobalBounds().width / 2)) - (this->range.getPosition().x + (this->range.getGlobalBounds().width / 2));
			this->dy = ((*itr)->getEnemySprite().getPosition().y + ((*itr)->getEnemySprite().getGlobalBounds().height / 2)) - (this->range.getPosition().y + (this->range.getGlobalBounds().height / 2));
			float d = std::sqrt(dx * dx + dy * dy);
			if (d <= (((*itr)->getEnemySprite().getGlobalBounds().width / 2) + this->range.getGlobalBounds().width / 2)) {
				this->target = *itr;
			}
		}
	}
}


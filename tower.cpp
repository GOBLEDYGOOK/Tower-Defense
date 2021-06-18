#include "tower.h"

//Constructors /Destructors
Tower::Tower(WaveContainer& waveContainer, int radius, std::string path, int cost, int dmg)
{
	this->waveContainer = &waveContainer;
	this->initVariables(cost, dmg);
	this->initTexture(path);
	this->initRange(radius);
	this->nextWave();
	std::string* tmp = new std::string[3];
	tmp[0] = std::to_string(this->getLevel() + 1);
	tmp[1] = std::to_string(this->getDmg());
	tmp[2] = std::to_string(int(this->range.getRadius()));
	this->dynamicText.setText(tmp);
	this->upgradeCost();
	this->upgradeButton.setCost(this->cost);
}

Tower::Tower(int radius, std::string path, int cost, int dmg)
{
	this->initVariables(cost, dmg);
	this->initTexture(path);
	this->initRange(radius);
	
}
Tower::~Tower()
{
	delete this->wave;
}
//Private functions
void Tower::initVariables(int cost, int dmg)
{
	this->level = 0;
	this->isClicked = false;
	this->cost = cost;
	this->dmg = dmg;
}

void Tower::initTexture(std::string path)
{
	
	if (!this->towerTexture.loadFromFile(path))
	{
		MessageBox(0, "Error! File doesnt exist (Tower class)", 0, 0);
		exit(0);
	}
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

UpgradeButton Tower::getUpgradeButton() const
{
	return this->upgradeButton;
}


//Accessors
DynamicText Tower::getDynamicText() const
{
	return this->dynamicText;
}

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

bool Tower::getIsClicked() const
{
	return this->isClicked;
}

WaveContainer* Tower::getWaveContainer() const
{
	return this->waveContainer;
}

sf::Vector2f Tower::getCenter() const
{
	return sf::Vector2f(this->towerSprite.getPosition().x + 45, this->towerSprite.getPosition().y + 45);
}

void Tower::upgradeCost()
{
	this->cost += 10;
}

//public functions
void Tower::changeIsClicked()
{
	if (this->isClicked == false)this->isClicked = true;
	else this->isClicked = false;

}
void Tower::setPosition(sf::Vector2f position)
{
	this->towerSprite.setPosition(position);
	this->range.setPosition(this->towerSprite.getPosition().x - this->range.getRadius() + 45, this->towerSprite.getPosition().y - this->range.getRadius() + 45);
	this->dynamicText.setPosition(position);
	this->upgradeButton.setPosition(position);
}

void Tower::upgrade()
{
	this->upgradeCost();
	this->upgradeButton.setCost(this->cost);
	this->range.setRadius(this->range.getRadius() + 0.1*this->range.getRadius() +5);
	this->dmg = this->dmg + 0.4*this->dmg + 3;
	this->setPosition(this->towerSprite.getPosition());
}

void Tower::levelUp()
{
	if (this->level != this->maxLevel) {
		this->level++;
		this->upgrade();
		std::string* tmp = new std::string[3];
		tmp[0] = std::to_string(this->getLevel() + 1);
		tmp[1] = std::to_string(this->getDmg());
		tmp[2] = std::to_string(int(this->range.getRadius()));
		this->dynamicText.setText(tmp);
	}
}

void Tower::nextWave()
{
	if (!this->waveContainer->empty()) this->wave = this->waveContainer->front();
}



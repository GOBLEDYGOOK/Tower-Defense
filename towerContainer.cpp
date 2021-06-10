#include "towerContainer.h"

//Constructor
TowerContainer::TowerContainer(WaveContainer& waveContainer)
{
	this->waveContainer = &waveContainer;
}

TowerContainer::TowerContainer()
{
	;
}

//Destructor
TowerContainer::~TowerContainer()
{
}

//Public functions
void TowerContainer::add(sf::Vector2f mousePos, int i)
{
	int x = mousePos.x / 90;
	int y = mousePos.y / 90;
	Tower* tmp;
	x *= 90;
	y *= 90;

	switch (i) {
	case 0: {
		tmp = new TowerBasic(*this->waveContainer);
		tmp->setPosition(sf::Vector2f(x, y));
		tmp->setBullet();
		tmp->upgradeCost();
		this->towerContainer.push_back(tmp);
		break;
	case 1:
		tmp = new TowerTripleShot(*this->waveContainer);
		tmp->setPosition(sf::Vector2f(x, y));
		tmp->setBullet();
		tmp->upgradeCost();
		this->towerContainer.push_back(tmp);
		break;
	case 2:
		tmp = new TowerSniper(*this->waveContainer);
		tmp->setPosition(sf::Vector2f(x, y));
		tmp->setBullet();
		tmp->upgradeCost();
		this->towerContainer.push_back(tmp);
		break;
	}

	}
	
	
	
}

void TowerContainer::draw(sf::RenderWindow & window)
{
	for (auto itr = this->towerContainer.begin(); itr != this->towerContainer.end(); itr++) {
		(*itr)->draw(window);
	}
	for (auto itr = this->towerContainer.begin(); itr != this->towerContainer.end(); itr++) {
		(*itr)->drawClicked(window);
	}
}

void TowerContainer::clickedTower(sf::Vector2f mousePos)
{
	for (auto itr = this->towerContainer.begin(); itr != this->towerContainer.end(); itr++) {
		if ((*itr)->getIsClicked()) {
			if((*itr)->getSprite().getGlobalBounds().contains(mousePos)){
				(*itr)->changeIsClicked();
			}
			return;
		}
	}
	for (auto itr = this->towerContainer.begin(); itr != this->towerContainer.end(); itr++) {
		if ((*itr)->getSprite().getGlobalBounds().contains(mousePos)) {
			(*itr)->changeIsClicked();
			break;
		}
	}
}

int TowerContainer::clickedUpgrade(sf::Vector2f mousePos, int totalGold)
{
	int gold;
	for (auto itr = this->towerContainer.begin(); itr != this->towerContainer.end(); itr++) {
		if ((*itr)->getIsClicked() && (*itr)->getUpgradeButton().getButtonSprite().getGlobalBounds().contains(mousePos)) {
			if (totalGold >= (*itr)->getCost() && (*itr)->getLevel() != (*itr)->getMaxLevel()) {
				gold = (*itr)->getCost();
				(*itr)->levelUp();
				return gold;
			}
			break;
		}
	}
	return 0;
}

void TowerContainer::update()
{
	for (auto itr = this->towerContainer.begin(); itr != this->towerContainer.end(); itr++) {
		(*itr)->update();
		(*itr)->shoot();
	}
}

void TowerContainer::setCostUpgrade()
{
	for (auto itr = this->towerContainer.begin(); itr != this->towerContainer.end(); itr++) {
		(*itr)->getUpgradeButton().setCost((*itr)->getCost());
	}
}

void TowerContainer::nextWave()
{
	for (auto itr = this->towerContainer.begin(); itr != this->towerContainer.end(); itr++) {
		(*itr)->nextWave();
	}
}

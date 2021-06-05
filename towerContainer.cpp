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
		this->towerContainer.push_back(tmp);
		break;
	}

	}
	
	
	
}

void TowerContainer::draw(sf::RenderWindow & window)
{
	for (auto itr = this->towerContainer.begin(); itr != this->towerContainer.end(); itr++) {
		window.draw((*itr)->getSprite());
	}
}

void TowerContainer::update()
{
	for (auto itr = this->towerContainer.begin(); itr != this->towerContainer.end(); itr++) {
		(*itr)->update();
		(*itr)->shoot();
	}
}

void TowerContainer::nextWave()
{
	for (auto itr = this->towerContainer.begin(); itr != this->towerContainer.end(); itr++) {
		(*itr)->nextWave();
	}
}

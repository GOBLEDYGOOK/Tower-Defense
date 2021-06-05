#include "towerBasic.h"

//Constructor
TowerBasic::TowerBasic(WaveContainer& waveContainer, int radius, std::string path, int cost, int dmg) :Tower(waveContainer, radius, path, cost, dmg)
{
	this->target = nullptr;
	this->isReady = 0;
}

TowerBasic::TowerBasic(int radius, std::string path, int cost, int dmg) : Tower(radius, path, cost, dmg)
{
	this->target = nullptr;
	this->isReady = 0;
}

//Destructor
TowerBasic::~TowerBasic()
{
	;
}

//Private functions

//Accessors


void TowerBasic::upgrade()
{
	;
}

void TowerBasic::levelUp()
{
	;
}

void TowerBasic::shoot()
{
	
	if (this->target != nullptr && this->target->getIsDead())this->target = nullptr;
	else if (this->target != nullptr && this->isReady == 90) {
		this->target->receiveDamage(this->getDmg());
		this->isReady = 0;
	}
	else if (this->isReady < 90) {
		this->isReady++;
	}
	else {
		;
	}

}

void TowerBasic::update()
{
	
	
		for (auto itr = this->getWave()->begin(); itr != this->getWave()->end(); itr++) {
			this->dx = ((*itr)->getEnemySprite().getPosition().x + ((*itr)->getEnemySprite().getGlobalBounds().width / 2)) - (this->getRange().getPosition().x + (this->getRange().getGlobalBounds().width / 2));
			this->dy = ((*itr)->getEnemySprite().getPosition().y + ((*itr)->getEnemySprite().getGlobalBounds().height / 2)) - (this->getRange().getPosition().y + (this->getRange().getGlobalBounds().height / 2));
			this->d = std::sqrt(dx * dx + dy * dy);
			if (this->target == nullptr) {
				if (d <= (((*itr)->getEnemySprite().getGlobalBounds().width / 2) + this->getRange().getGlobalBounds().width / 2)) {
					this->target = *itr;
				}
			}
			if (this->target == (*itr) && (d > (((*itr)->getEnemySprite().getGlobalBounds().width / 2) + this->getRange().getGlobalBounds().width / 2))) {
				this->target = nullptr;
			}
		}
	
	
	

}

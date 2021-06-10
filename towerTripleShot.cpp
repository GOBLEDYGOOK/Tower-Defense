#include "towerTripleShot.h"

//private functions
void TowerTripleShot::setBullet()
{
	for (size_t i = 0; i < numberOfTargets; i++) {
		this->bullet[i] = new Bullet(this->getCenter());
	}
	
}

bool TowerTripleShot::differentTargets(Enemy * enemy)
{
	if (this->target[0] == enemy || this->target[0] == enemy || this->target[1] == enemy) return false;
	return true;
}

//Constructor
TowerTripleShot::TowerTripleShot(WaveContainer& waveContainer, int radius, std::string path, int cost, int dmg) :Tower(waveContainer, radius, path, cost, dmg)
{
	for (size_t i = 0; i < numberOfTargets; i++) {
		this->target[i] = nullptr;
	}
	this->isReady = 90;
}

TowerTripleShot::TowerTripleShot(int radius, std::string path, int cost, int dmg) : Tower(radius, path, cost, dmg)
{
	for (size_t i = 0; i < numberOfTargets; i++) {
		this->target[i] = nullptr;
	}
}

//Destructor
TowerTripleShot::~TowerTripleShot()
{
	;
}

//Accessors

//Public functions


void TowerTripleShot::shoot()
{
	for (size_t i = 0; i < numberOfTargets; i++) {
		if (this->target[i] != nullptr) {

			if (this->target[i]->getIsDead()) {
				this->target[i] = nullptr;
				this->bullet[i]->reset();
			}
			else if (this->isReady == 90) {
				this->bullet[i]->shoot(this->target[i]->getCenter());
			}
			if (this->bullet[i]->getIsStarted()) {
				this->bullet[i]->update(this->target[i]->getCenter(), *this->target[i], this->getDmg());
			}
		}
	}
	if (this->isReady < 90) {
		this->isReady++;
	}
	else if (this->isReady == 90) {
		this->isReady = 0;
	}
}

void TowerTripleShot::update()
{
	
	for (size_t i = 0; i < numberOfTargets; i++) {
		for (auto itr = this->getWave()->begin(); itr != this->getWave()->end(); itr++) {
			if ((*itr)->getIsStarted()) {
					this->dx[i] = ((*itr)->getEnemySprite().getPosition().x + ((*itr)->getEnemySprite().getGlobalBounds().width / 2)) - (this->getRange().getPosition().x + (this->getRange().getGlobalBounds().width / 2));
					this->dy[i] = ((*itr)->getEnemySprite().getPosition().y + ((*itr)->getEnemySprite().getGlobalBounds().height / 2)) - (this->getRange().getPosition().y + (this->getRange().getGlobalBounds().height / 2));
					this->d[i] = std::sqrt(dx[i] * dx[i] + dy[i] * dy[i]);
				if (this->target[i] == nullptr) {
					
					if (this->differentTargets(*itr) && this->d[i] <= (((*itr)->getEnemySprite().getGlobalBounds().width / 2) + this->getRange().getGlobalBounds().width / 2)) {
						this->target[i] = *itr;
						break;
					}
					
				}
				if (!this->bullet[i]->getIsStarted() && this->target[i] == (*itr) && (this->d[i] > (((*itr)->getEnemySprite().getGlobalBounds().width / 2) + this->getRange().getGlobalBounds().width / 2))) {
					this->target[i] = nullptr;
					this->bullet[i]->reset();
				}
				if(this->target[i] == (*itr)) {
					break;
				}
			}
		}
	}


}

void TowerTripleShot::draw(sf::RenderWindow & window)
{
	window.draw(this->getSprite());
	for (size_t i = 0; i < numberOfTargets; i++) {
		this->bullet[i]->draw(window);
	}
}

void TowerTripleShot::drawClicked(sf::RenderWindow & window)
{
	if (this->getIsClicked()) {
		window.draw(this->getRange());
		this->getDynamicText().draw(window);
		if (this->getLevel() != this->getMaxLevel()) {
			this->getUpgradeButton().draw(window);
		}
	}
}

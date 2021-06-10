#include "towerSniper.h"

//private functions
void TowerSniper::setBullet()
{

	this->bullet = new Bullet(this->getCenter());
}

//Constructor
TowerSniper::TowerSniper(WaveContainer& waveContainer, int radius, std::string path, int cost, int dmg) :Tower(waveContainer, radius, path, cost, dmg)
{
	this->target = nullptr;
	this->isReady = 220;
}

TowerSniper::TowerSniper(int radius, std::string path, int cost, int dmg) : Tower(radius, path, cost, dmg)
{
	this->target = nullptr;
	this->isReady = 220;
}

//Destructor
TowerSniper::~TowerSniper()
{
	;
}

//Private functions

//Accessors

//Public functions
void TowerSniper::shoot()
{

	if (this->target != nullptr) {

		if (this->target->getIsDead()) {
			this->target = nullptr;
			this->bullet->reset();
		}
		else if (this->isReady == 220) {
			this->bullet->shoot(this->target->getCenter());
			this->isReady = 0;
		}
		if (this->bullet->getIsStarted()) {
			this->bullet->update(this->target->getCenter(), *this->target, this->getDmg());
		}
	}
	if (this->isReady < 220) {
		this->isReady++;
	}

}

void TowerSniper::update()
{

	for (auto itr = this->getWave()->begin(); itr != this->getWave()->end(); itr++) {
		if ((*itr)->getIsStarted()) {
			this->dx = ((*itr)->getEnemySprite().getPosition().x + ((*itr)->getEnemySprite().getGlobalBounds().width / 2)) - (this->getRange().getPosition().x + (this->getRange().getGlobalBounds().width / 2));
			this->dy = ((*itr)->getEnemySprite().getPosition().y + ((*itr)->getEnemySprite().getGlobalBounds().height / 2)) - (this->getRange().getPosition().y + (this->getRange().getGlobalBounds().height / 2));
			this->d = std::sqrt(dx * dx + dy * dy);
			if (this->target == nullptr) {
				if (d <= (((*itr)->getEnemySprite().getGlobalBounds().width / 2) + this->getRange().getGlobalBounds().width / 2)) {
					this->target = *itr;
					break;
				}
			}
			if (!this->bullet->getIsStarted() && this->target == (*itr) && (d > (((*itr)->getEnemySprite().getGlobalBounds().width / 2) + this->getRange().getGlobalBounds().width / 2))) {
				this->target = nullptr;
				this->bullet->reset();
			}
			if (this->target == (*itr))break;
		}
	}


}

void TowerSniper::draw(sf::RenderWindow & window)
{

	window.draw(this->getSprite());
	this->bullet->draw(window);

}

void TowerSniper::drawClicked(sf::RenderWindow & window)
{
	if (this->getIsClicked()) {
		window.draw(this->getRange());
		this->getDynamicText().draw(window);
		if (this->getLevel() != this->getMaxLevel()) {
			this->getUpgradeButton().draw(window);
		}
	}
}

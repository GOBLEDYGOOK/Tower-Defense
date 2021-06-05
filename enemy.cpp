#include "enemy.h"

//Private functions
void Enemy::initVariables(std::string path, int gold, int hp, int dmg, float velocity)
{
	this->isDead = false;
	this->direction = 0;
	this->hp = hp;
	this->gold = gold;
	this->damage = dmg;
	this->isStarted = false;
	this->velocity = velocity;
	this->enemyTexture.loadFromFile(path);
	this->enemySprite.setTexture(this->enemyTexture);
	this->enemySprite.setPosition(270.0f, -90.0f);
	this->hpBar = new HpBar(this->hp);
	this->hpBar->setPosition(sf::Vector2f(this->enemySprite.getPosition().x + 15, this->enemySprite.getPosition().y + 80));
	this->hpBar->setSize(sf::Vector2f(60.0f, 8.0f));
}

//Consturctors /Destructors
Enemy::Enemy(std::string path, int gold, int hp, int dmg, float velocity)
{
	this->initVariables(path, gold, hp, dmg, velocity);
}

Enemy::~Enemy()
{

}


//Accessors
bool Enemy::getIsDead() const
{
	return this->isDead;
}

bool Enemy::getIsStarted() const
{
	return this->isStarted;
}

int Enemy::getHp() const
{
	return this->hp;
}

int Enemy::getGold() const
{
	return this->gold;
}

int Enemy::getDamage() const
{
	return this->damage;
}

int Enemy::getDirection() const
{
	return this->direction;
}

float Enemy::getVelocity() const
{
	return this->velocity;
}

sf::Sprite Enemy::getEnemySprite() const
{
	return this->enemySprite;
}

HpBar Enemy::getHpBar() const
{
	return *this->hpBar;
}

//public functions
void Enemy::startEnemy()
{
	this->isStarted = true;
}

int Enemy::receiveDamage(int dmg)
{

	this->hp -= dmg;
	if (this->hp <= 0)this->isDead = true;
	return this->hp;

}

void Enemy::update(sf::RenderWindow& window)
{
	/*
		move down enemy.move(0, speed)
		move right enemy.move(speed, 0)
		move left enemy.move(-speed, 0)
		move up enemy.move(0, -speed)

	*/

	this->hpBar->updateEnemy(this->hp, this->enemySprite.getPosition());
	
	switch (this->direction) {
	case 0:
		this->enemySprite.move(0.0f, this->velocity);
		this->hpBar->move(0.0f, this->velocity);
		break;
	case 1:
		this->enemySprite.move(this->velocity, 0.0f);
		this->hpBar->move(this->velocity, 0.0f);
		break;
	case 2:
		this->enemySprite.move(-this->velocity, 0.0f);
		this->hpBar->move(-this->velocity, 0.0f);
		break;
	case 3:
		this->enemySprite.move(0.0f, -this->velocity);
		this->hpBar->move(0.0f, -this->velocity);
		break;
	}
	this->direction = this->mapTiles.chooseDirection(window, this->enemySprite.getPosition(), this->direction);
	if (this->hp <= 0)this->isDead = true;
}

void Enemy::draw(sf::RenderWindow & window)
{
	window.draw(this->enemySprite);
	this->hpBar->draw(window);
}


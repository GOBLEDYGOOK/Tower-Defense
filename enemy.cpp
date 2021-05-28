#include "enemy.h"

//Private functions
void Enemy::initVariables(std::string path, int gold, int hp, int dmg, float velocity)
{
	this->isDead = false;
	this->direction = 0;
	this->hp = hp;
	this->gold = gold;
	this->damage = dmg;
	this->velocity = velocity;
	this->enemyTexture.loadFromFile(path);
	this->enemySprite.setTexture(this->enemyTexture);
	this->enemySprite.setPosition(270.0f, -90.0f);
	this->hpBar = new HpBar(this->hp, this->enemySprite.getPosition());
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
int Enemy::receiveDamage(int dmg)
{
	this->hp -= dmg;
	if (this->hp <= 0)this->isDead = true;
	return this->hp;
}

void Enemy::update(sf::RenderWindow& window)
{
	/*
		move down enemy.move(0,speed)
		move right enemy.move(speed,0)
		move left enemy.move(-speed,0)
		move up enemy.move(0,-speed)

	*/
	this->receiveDamage(1);
	this->hpBar->update(this->hp, this->enemySprite.getPosition());
	
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
}

void Enemy::draw(sf::RenderWindow & window)
{
	window.draw(this->enemySprite);
	this->hpBar->draw(window);
}


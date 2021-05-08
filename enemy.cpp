#include "enemy.h"

//Consturctors /Destructors
Enemy::Enemy()
{

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

float Enemy::getVelocity() const
{
	return this->velocity;
}

sf::Vector2i Enemy::getEnemyPos() const
{
	return this->enemyPos;
}

sf::Sprite Enemy::getTexture() const
{
	return this->texture;
}

//public functions
void Enemy::receiveDamage(int dmg)
{
	this->hp -= dmg;
	if (this->hp <= 0)this->isDead = true;
}

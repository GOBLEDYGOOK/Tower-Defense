#include "bullet.h"

//Normalize function
sf::Vector2f normalize(sf::Vector2f target, sf::Vector2f current)
{
	return target - current;
}

//Private functions
void Bullet::initBullet()
{
	if (!this->textureBullet.loadFromFile("bullet.png"))
	{
		MessageBox(0, "Error! bullet.png doesn't exist", 0, 0);
		exit(0);
	}
	this->spriteBullet.setTexture(this->textureBullet);
	this->spriteBullet.setPosition(this->towerCenter);
}

//Constructor
Bullet::Bullet(sf::Vector2f towerCenter)
{
	this->towerCenter = sf::Vector2f(towerCenter.x - 2, towerCenter.y - 2);
	this->isStarted = false;
	this->initBullet();
}

//Destructor
Bullet::~Bullet()
{
	;
}

bool Bullet::getIsStarted() const
{
	return this->isStarted;
}

//Public functions
void Bullet::shoot(sf::Vector2f enemyCenter)
{
	this->enemyCenter = sf::Vector2f(enemyCenter.x - 1, enemyCenter.y - 1);
	this->direction = normalize(this->enemyCenter, this->towerCenter);
	this->isStarted = true;
}

void Bullet::update(sf::Vector2f enemyCenter, Enemy& enemy, int dmg)
{
	
	this->direction = normalize(enemyCenter, this->spriteBullet.getPosition());
	float magnitude = sqrt((direction.x * direction.x) + (direction.y * direction.y));
	sf::Vector2f unitVector(direction.x / magnitude, direction.y / magnitude);
	this->spriteBullet.move(10.0f * unitVector);
	if ((1.035f * enemyCenter.x >= this->spriteBullet.getPosition().x) && (enemyCenter.x * 0.965f <= this->spriteBullet.getPosition().x) &&
		(1.035f * enemyCenter.y >= this->spriteBullet.getPosition().y) && (0.965f * enemyCenter.y <= this->spriteBullet.getPosition().y)) {
		enemy.receiveDamage(dmg);
		this->reset();
	}
}

void Bullet::draw(sf::RenderWindow & window)
{
	window.draw(this->spriteBullet);
}

void Bullet::reset()
{
	this->spriteBullet.setPosition(this->towerCenter);
	this->isStarted = false;
}



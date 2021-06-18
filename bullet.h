#pragma once
#include <SFML/Graphics.hpp>
#include "enemyBasic.h"
#include "enemyTank.h"
#include "enemyFast.h"
#include "windows.h"

class Bullet
{
	//Private variables
	sf::Texture textureBullet;
	sf::Sprite spriteBullet;
	sf::Vector2f towerCenter;
	sf::Vector2f enemyCenter;
	sf::Vector2f direction;
	bool isStarted;

	//Private functions
	void initBullet();
public:
	//Constructors /Destructors
	Bullet(sf::Vector2f turretCenter);
	~Bullet();

	//Accessors
	bool getIsStarted() const;

	//Public functions
	void shoot(sf::Vector2f enemyCenter);
	void update(sf::Vector2f enemyCenter, Enemy& enemy, int dmg);
	void draw(sf::RenderWindow& window);
	void reset();
};


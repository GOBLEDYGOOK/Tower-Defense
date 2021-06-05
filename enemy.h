#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "hpBar.h"
#include "mapTiles.h"

/*
	Class of enemy
*/
class Enemy{
	//Private variables
	bool isDead;
	bool isStarted;
	int hp;
	int gold;
	int damage;
	int direction;
	float velocity;
	sf::Sprite enemySprite;
	sf::Texture enemyTexture;
	MapTiles mapTiles;
	HpBar *hpBar;

	//Private functions
	void initVariables(std::string path, int gold, int hp, int dmg, float velocity);
public:

	//Consturctors /Destructors
	Enemy(std::string path, int gold, int hp, int dmg, float velocity);
	virtual ~Enemy();

	//Accessors
	bool getIsDead() const;
	bool getIsStarted() const;
	int getHp() const;
	int getGold() const;
	int getDamage() const;
	int getDirection() const;
	float getVelocity() const;
	sf::Sprite getEnemySprite() const;
	HpBar getHpBar() const;

	//public functions
	void startEnemy();
	int receiveDamage(int dmg);
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
};


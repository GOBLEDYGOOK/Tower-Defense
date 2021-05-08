#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

/*
	Abstract class of enemy
*/
class Enemy{
	//Private variables
	bool isDead;
	int hp;
	int gold;
	int damage;
	float velocity;
	sf::Sprite texture;
	sf::Vector2i enemyPos;

public:

	//Consturctors /Destructors
	Enemy();
	virtual ~Enemy();

	//Accessors
	bool getIsDead() const;
	int getHp() const;
	int getGold() const;
	int getDamage() const;
	float getVelocity() const;
	sf::Vector2i getEnemyPos() const;
	sf::Sprite getTexture() const;

	//public functions
	void receiveDamage(int dmg);

};


#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

/*
	Abstract class of tower
*/

class Tower{
	//Private variables
	int level = 1;
	static const int maxLevel = 3;
	int dmg;
	int cost;
	int range;
	sf::Sprite texture;
	sf::Vector2i towerPos;

public:
	//Constructors /Destructors
	Tower();
	virtual ~Tower();

	//Accessors
	int retDmg() const;
	int retCost() const;
	int retRange() const;
	int retLevel() const;
	int retMaxLevel() const;
	sf::Sprite retTexture() const;
	sf::Vector2i retTowerPos() const;

	//public functions
	virtual void upgrade();
	void levelUp();
};


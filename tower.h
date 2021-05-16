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
	static const int maxLevel = 3;
	sf::Sprite towerSprite;
	sf::Texture towerTexture;
	sf::Vector2i towerPos;
	sf::Vector2i rangePos;
	sf::CircleShape range;
	int level;
	int dmg;
	int cost;

	//Private functions
	void initVariables(int cost, int dmg);
	void initTexture(std::string path);
	void initRange(int radius);
public:
	//Constructors /Destructors
	Tower(int radius, std::string path, int cost, int dmg);
	virtual ~Tower();

	//Accessors

	virtual int retMaxLevel() const;
	virtual int getDmg() const;
	virtual int getCost() const;
	virtual sf::CircleShape getRange() const;
	virtual int getLevel() const;
	virtual sf::Sprite getSprite() const;
	virtual sf::Vector2i getTowerPos() const;
	virtual sf::Texture getTexture()const;

	//public functions
	virtual void setPosition(sf::Vector2f position);
	virtual void upgrade() = 0;
	virtual void levelUp() = 0;
};


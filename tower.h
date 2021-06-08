#pragma once
#include "waveContainer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <cmath>

/*
	Abstract class of tower
*/

class Tower{

	//Private variables
	static const int maxLevel = 3;
	
	WaveContainer* waveContainer;
	Wave* wave;
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
	Tower(WaveContainer& waveContainer, int radius, std::string path, int cost, int dmg);
	Tower(int radius, std::string path, int cost, int dmg);
	virtual ~Tower();

	//Accessors
	Wave* getWave() const;
	virtual int getMaxLevel() const;
	virtual int getDmg() const;
	virtual int getCost() const;
	virtual sf::CircleShape getRange() const;
	virtual int getLevel() const;
	virtual sf::Sprite getSprite() const;
	virtual sf::Vector2f getCenter() const;
	virtual sf::Texture getTexture()const;
	WaveContainer* getWaveContainer() const;

	//public functions
	virtual void setPosition(sf::Vector2f position);
	virtual void shoot() = 0;
	virtual void update() = 0;
	virtual void upgrade() = 0;
	virtual void levelUp() = 0;
	virtual void setBullet() = 0;
	virtual void draw(sf::RenderWindow & window) = 0;
	virtual void nextWave();
};


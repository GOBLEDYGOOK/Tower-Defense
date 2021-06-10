#pragma once
#include "waveContainer.h"
#include "dynamicText.h"
#include "upgradeButton.h"
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
	static const int maxLevel = 2;
	
	WaveContainer* waveContainer;
	bool isClicked;
	UpgradeButton upgradeButton;
	Wave* wave;
	sf::Sprite towerSprite;
	sf::Texture towerTexture;
	sf::Vector2i towerPos;
	sf::Vector2i rangePos;
	sf::CircleShape range;
	DynamicText dynamicText;
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
	UpgradeButton getUpgradeButton() const;
	DynamicText getDynamicText() const;
	virtual int getMaxLevel() const;
	virtual int getDmg() const;
	virtual int getCost() const;
	virtual sf::CircleShape getRange() const;
	virtual int getLevel() const;
	virtual sf::Sprite getSprite() const;
	virtual sf::Vector2f getCenter() const;
	virtual sf::Texture getTexture()const;
	bool getIsClicked()const;
	WaveContainer* getWaveContainer() const;

	//public functions
	void upgradeCost();
	virtual void changeIsClicked();
	virtual void setPosition(sf::Vector2f position);
	virtual void shoot() = 0;
	virtual void update() = 0;
	virtual void levelUp();
	virtual void upgrade();
	virtual void setBullet() = 0;
	virtual void draw(sf::RenderWindow & window) = 0;
	virtual void drawClicked(sf::RenderWindow & window) = 0;
	virtual void nextWave();
};


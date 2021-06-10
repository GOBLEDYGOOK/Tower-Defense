#pragma once
#pragma once
#include "tower.h"
#include "bullet.h"
#include <string>

/*
	Class of basic tower
*/

class TowerSniper :public Tower
{
	//Private variables
	int isReady;
	float dx;
	float dy;
	float d;
	Bullet* bullet;
	Enemy *target;
	//Private functions

public:
	//Constructos /Destructors
	TowerSniper(WaveContainer& waveContainer, int radius = 330, std::string path = "towerSniper.png", int cost = 150, int dmg = 50);
	TowerSniper(int radius = 330, std::string path = "towerSniper.png", int cost = 150, int dmg = 50);
	virtual ~TowerSniper();

	//Accesors

	//Public functions
	void setBullet();
	virtual void shoot();
	virtual void update();
	virtual void draw(sf::RenderWindow& window);
	virtual void drawClicked(sf::RenderWindow& window);
};



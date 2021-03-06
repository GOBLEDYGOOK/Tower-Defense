#pragma once
#include "tower.h"
#include "bullet.h"
#include <string>

/*
	Class of basic tower
*/

class TowerBasic :public Tower
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
	TowerBasic(WaveContainer& waveContainer, int radius = 180, std::string path = "towerBasic.png", int cost = 100, int dmg = 25);
	TowerBasic(int radius = 180, std::string path = "towerBasic.png", int cost = 100, int dmg = 25);
	virtual ~TowerBasic();
	
	//Accesors
	
	//Public functions
	void setBullet();
	virtual void shoot();
	virtual void update();
	virtual void draw(sf::RenderWindow& window);
	virtual void drawClicked(sf::RenderWindow& window);
};


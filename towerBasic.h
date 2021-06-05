#pragma once
#include "tower.h"
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
	Enemy *target;
	//Private functions
	
public:
	//Constructos /Destructors
	TowerBasic(WaveContainer& waveContainer, int radius = 180, std::string path = "enemyTank.png", int cost = 100, int dmg = 10);
	TowerBasic(int radius = 180, std::string path = "enemyTank.png", int cost = 100, int dmg = 10);
	virtual ~TowerBasic();
	
	//Accesors
	

	//Public functions
	virtual void upgrade();
	virtual void levelUp();
	virtual void shoot();
	virtual void update();
};


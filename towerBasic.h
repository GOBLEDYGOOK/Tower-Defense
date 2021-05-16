#pragma once
#include "tower.h"
#include <string>
/*
	Class of basic tower
*/

class TowerBasic :public Tower
{
	//Private variables

	//Private functions
	
public:
	//Constructos /Destructors
	TowerBasic(int radius = 180, std::string path = "enemyTank.png", int cost = 100, int dmg = 10);
	virtual ~TowerBasic();
	
	//Accesors
	

	//Public functions
	virtual void upgrade();
	virtual void levelUp();
};


#pragma once
#include "enemy.h"

class EnemyTank : public Enemy
{
	//Private variables
	

	//Private functions

public:
	//Constructos /Destructors
	EnemyTank(std::string path = "enemyTank.png", int gold = 35, int hp = 100, int dmg = 10, float velocity = 1.0f);
	virtual ~EnemyTank();

	//Accesors

	//Public functions
	
};


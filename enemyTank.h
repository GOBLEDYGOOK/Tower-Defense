#pragma once
#include "enemy.h"

class EnemyTank : public Enemy
{
	//Private variables
	

	//Private functions

public:
	//Constructos /Destructors
	EnemyTank(int modifier, std::string path = "enemyTank.png", int gold = 25, int hp = 150, int dmg = 18, float velocity = 1.0f);
	virtual ~EnemyTank();

	//Accesors

	//Public functions
	
};


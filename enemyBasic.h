#pragma once
#include "enemy.h"
class EnemyBasic :public Enemy
{
	//Private variables

	//Private functions

public:
	//Constructos /Destructors
	EnemyBasic(int modifier, std::string path = "enemyBasic.png", int gold = 15, int hp = 50, int dmg = 13, float velocity = 1.0f);
	virtual ~EnemyBasic();

	//Accesors


	//Public functions
};


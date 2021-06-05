#pragma once
#include "enemy.h"
class EnemyBasic :public Enemy
{
	//Private variables

	//Private functions

public:
	//Constructos /Destructors
	EnemyBasic(std::string path = "enemyBasic.png", int gold = 20, int hp = 50, int dmg = 6, float velocity = 1.0f);
	virtual ~EnemyBasic();

	//Accesors


	//Public functions
};


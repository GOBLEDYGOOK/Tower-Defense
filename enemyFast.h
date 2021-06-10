#pragma once
#include "enemy.h"
class EnemyFast :public Enemy
{
	//Private variables

	//Private functions

public:
	//Constructos /Destructors
	EnemyFast(int modifier, std::string path = "enemyFast.png", int gold = 10, int hp = 40, int dmg = 13, float velocity = 2.0f);
	virtual ~EnemyFast();

	//Accesors


	//Public functions


};


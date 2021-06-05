#pragma once
#include "enemy.h"
class EnemyFast :public Enemy
{
	//Private variables

	//Private functions

public:
	//Constructos /Destructors
	EnemyFast(std::string path = "enemyFast.png", int gold = 20, int hp = 50, int dmg = 6, float velocity = 2.0f);
	virtual ~EnemyFast();

	//Accesors


	//Public functions


};


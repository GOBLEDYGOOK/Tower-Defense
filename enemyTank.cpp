#include "enemyTank.h"
//Constructor
EnemyTank::EnemyTank(int modifier, std::string path, int gold, int hp, int dmg, float velocity) : Enemy(modifier, path, gold, hp, dmg, velocity)
{
	
}

//Destructor
EnemyTank::~EnemyTank()
{
}

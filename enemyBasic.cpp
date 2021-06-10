#include "enemyBasic.h"
//Constructor
EnemyBasic::EnemyBasic(int modifier, std::string path, int gold, int hp, int dmg, float velocity) : Enemy(modifier, path, gold, hp, dmg, velocity)
{

}

//Destructor
EnemyBasic::~EnemyBasic()
{
}

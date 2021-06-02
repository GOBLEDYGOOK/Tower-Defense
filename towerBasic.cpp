#include "towerBasic.h"

//Constructor
TowerBasic::TowerBasic(WaveContainer& waveContainer, int radius, std::string path, int cost, int dmg) :Tower(waveContainer, radius, path, cost, dmg)
{
	;
}

TowerBasic::TowerBasic(int radius, std::string path, int cost, int dmg) : Tower(radius, path, cost, dmg)
{
	;
}

//Destructor
TowerBasic::~TowerBasic()
{
	;
}

//Private functions

//Accessors


void TowerBasic::upgrade()
{
	;
}

void TowerBasic::levelUp()
{
	;
}

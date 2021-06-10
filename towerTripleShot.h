#pragma once
#include "tower.h"
#include "bullet.h"
class TowerTripleShot :public Tower
{
	//Private variables
	static const int numberOfTargets = 3;
	int isReady;
	float dx[numberOfTargets];
	float dy[numberOfTargets];
	float d[numberOfTargets];
	Bullet* bullet[numberOfTargets];
	Enemy *target[numberOfTargets];

	//Private functions

public:
	//Constructos /Destructors
	TowerTripleShot(WaveContainer& waveContainer, int radius = 140, std::string path = "towerTripleShot.png", int cost = 125, int dmg = 14);
	TowerTripleShot(int radius = 140, std::string path = "towerTripleShot.png", int cost = 125, int dmg = 14);
	virtual ~TowerTripleShot();

	//Accesors

	//Public functions
	void setBullet();
	bool differentTargets(Enemy * enemy);
	virtual void shoot();
	virtual void update();
	virtual void draw(sf::RenderWindow& window);
	virtual void drawClicked(sf::RenderWindow& window);
};


#pragma once
#include "enemyBasic.h"
#include "enemyTank.h"
#include "enemyFast.h"
#include <vector>
#include "base.h"
#include "time.h"

class Wave
{
	//Private variables
	std::vector <Enemy*> enemyContainer;

	//Private functions
	void initEnemyContainer(int numberOfBasic, int numberOfFast, int numberOfTank, int modifier = 0); // totalNumberOfEnemies = numberOfBasic + numberOfFast + numberOfTank
public:
	//Constructors /Destructors
	Wave(int numberOfBasic = 0, int numberOfFast = 0, int numberOfTank = 0, int modifier = 0); // totalNumberOfEnemies = numberOfBasic + numberOfFast + numberOfTank
	virtual ~Wave();

	//Public functions
	int update(sf::RenderWindow& window, Base& base);
	void draw(sf::RenderWindow& window);
	void startWave();
	std::vector<Enemy *>::iterator begin();
	std::vector<Enemy *>::iterator end();
	bool empty();
};


#pragma once
#include <SFML/Graphics.hpp>
#include "enemyBasic.h"
#include "enemyTank.h"
#include "enemyFast.h"
#include <vector>
#include "time.h"
#include <iostream>


class Wave
{
	//Private variables
	std::vector <Enemy*> enemyContainer;

	//Private functions
	void initEnemyContainer(int numberOfBasic, int numberOfFast, int numberOfTank); // totalNumberOfEnemies = numberOfBasic + numberOfFast + numberOfTank
public:
	//Constructors /Destructors
	Wave(int numberOfBasic = 0, int numberOfFast = 0, int numberOfTank = 0); // totalNumberOfEnemies = numberOfBasic + numberOfFast + numberOfTank
	virtual ~Wave();

	//Public functions
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void startWave();
	std::vector<Enemy *>::iterator begin();
	std::vector<Enemy *>::iterator end();
	bool empty();
};


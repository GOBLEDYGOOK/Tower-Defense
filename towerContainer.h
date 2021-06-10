#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "towerBasic.h"
#include "towerSniper.h"
#include "towerTripleShot.h"
#include <iostream>


class TowerContainer
{
	//Private variables
	std::vector <Tower*> towerContainer;
	WaveContainer* waveContainer;
	//Private functions

public:
	//Constructors /Destructors
	TowerContainer(WaveContainer& waveContainer);
	TowerContainer();
	~TowerContainer();

	//Public functions
	void add(sf::Vector2f mousePos, int i);
	void draw(sf::RenderWindow &window);
	void clickedTower(sf::Vector2f mousePos);
	int clickedUpgrade(sf::Vector2f mousePos, int totalGold);
	void update();
	void setCostUpgrade();
	void nextWave();
};


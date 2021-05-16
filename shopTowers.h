#pragma once
#include <SFML/Graphics.hpp>
#include "towerBasic.h"
#include <iostream>
/*
	class 
*/
class ShopTowers
{
	//Private variables
	static const int numberOfTowers = 4;
	int costs[numberOfTowers];
	sf::Text labelBasic[numberOfTowers];
	sf::Texture textureTowers[numberOfTowers];
	sf::Sprite spriteTowers[numberOfTowers];
	Tower* towers[numberOfTowers];
	bool isClicked[numberOfTowers];

	//Private functions
	void initVariables();
public:
	//Constructors /Destructors
	ShopTowers();
	virtual ~ShopTowers();

	//Accessors
	sf::Sprite getSpriteTower(size_t i) const;
	int getCost(size_t i) const;
	Tower* getTower(size_t i) const;
	bool getIsClicked(size_t i);
	const int getNumberOfTowers() const;
	
	//Public functions
	void changeIsClicked(size_t i);
};


#pragma once

#include "shopTowers.h"
#include "map.h"

class Shop : public ShopTowers{
	//Private functions
	int totalGold;
	ShopTowers shopTowers;
	Map map;
	sf::Texture mapGridTexture;
	sf::Sprite mapGrid;

	//Private functions
	void initVariables();

public:
	//Constructors /Destructors
	Shop();
	virtual ~Shop();

	//Accessors
	ShopTowers getShopTowers() const;
	sf::Sprite getMapGridSprite()const;

	//Public functions
	void draw(sf::RenderWindow& window);
	void drawClickedTower(sf::RenderWindow& window);
	void shopClicked(sf::RenderWindow &window);
	void buy();
};


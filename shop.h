#pragma once

#include "shopTowers.h"
#include "map.h"
#include "mapTiles.h"

class Shop : public ShopTowers{
	//Private variables
	//here will be a vector of towers
	int totalGold;
	ShopTowers shopTowers;
	Map map;
	MapTiles mapTiles;
	sf::RenderWindow* window;
	sf::Texture mapGridTexture;
	sf::Sprite mapGrid;

	//Private functions
	void initVariables();

public:
	//Constructors /Destructors
	Shop(sf::RenderWindow& window);
	Shop();
	virtual ~Shop();

	//Accessors
	ShopTowers getShopTowers() const;
	sf::Sprite getMapGridSprite()const;

	//Public functions
	void draw();
	void drawClickedTower();
	void shopClicked();
	void buy();
};


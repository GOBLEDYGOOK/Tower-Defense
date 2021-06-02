#pragma once
#include "shopTowers.h"
#include "map.h"
#include "mapTiles.h"
#include "towerContainer.h"

class Shop : public ShopTowers{

	//Private variables
	TowerContainer* towerContainer;
	int totalGold;
	ShopTowers shopTowers;
	Map map;
	MapTiles mapTiles;
	sf::Text goldLabel;
	sf::RenderWindow* window;
	sf::Texture mapGridTexture;
	sf::Sprite mapGrid;

	//Private functions
	void initVariables();
	void initGoldLabel();
public:
	//Constructors /Destructors
	Shop(sf::RenderWindow& window, TowerContainer& towerContainer);
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


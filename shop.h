#pragma once

#include "shopTowers.h"

class Shop : public ShopTowers{
	//Private functions
	int totalGold;
	ShopTowers shopTowers;
	sf::Texture mapGridTexture;
	sf::Sprite mapGrid;

	//Private functions
	void initVariables();

public:
	//Constructors /Destructors
	Shop();
	virtual ~Shop();

	//Public functions
	void draw(sf::RenderWindow& window);
	void shopClicked(sf::RenderWindow &window);
	//Accessors
	ShopTowers getShopTowers() const;
	sf::Sprite getMapGridSprite()const;
};


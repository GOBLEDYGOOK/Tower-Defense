#include "shop.h"

//Constructor
Shop::Shop()
{
	this->initVariables();
}

//Destructor
Shop::~Shop()
{
	
}

//Private functions
void Shop::initVariables()
{
	this->totalGold = 100;
	this->mapGridTexture.loadFromFile("mapGrid1.png");
	this->mapGrid.setTexture(this->mapGridTexture);
}

//Public functions
void Shop::draw(sf::RenderWindow & window)
{
	window.draw(this->shopTowers.getSpriteTower(0));
}

void Shop::shopClicked(sf::RenderWindow &window)
{
	sf::Vector2f mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

	if (this->shopTowers.getSpriteTower(0).getGlobalBounds().contains(mousePositionFloat)) {
		if (this->totalGold >= this->shopTowers.getTower(0)->getCost()) {

			this->changeIsClicked(0);
		}
	}

}

//Accessors
ShopTowers Shop::getShopTowers() const
{
	return this->shopTowers;
}

sf::Sprite Shop::getMapGridSprite()const
{
	return this->mapGrid;
}
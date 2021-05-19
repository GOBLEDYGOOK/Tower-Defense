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

//Accessors
ShopTowers Shop::getShopTowers() const
{
	return this->shopTowers;
}

sf::Sprite Shop::getMapGridSprite()const
{
	return this->mapGrid;
}

//Public functions
void Shop::draw(sf::RenderWindow & window)
{
	window.draw(this->shopTowers.getSpriteTower(0));
}

void Shop::drawClickedTower(sf::RenderWindow & window)
{
	sf::Vector2f mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
	switch (this->getIsClicked()) {
	case 0:
		std::cout << "elo";
		this->getShopTowers().getTower(0)->setPosition(sf::Vector2f(mousePositionFloat.x - 45.0f, mousePositionFloat.y - 45.0f));
		window.draw(this->getMapGridSprite());
		window.draw(this->getShopTowers().getTower(0)->getSprite());
		window.draw(this->getShopTowers().getTower(0)->getRange());
	}

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

void Shop::buy()
{

}

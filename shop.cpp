#include "shop.h"

//Constructor
Shop::Shop(sf::RenderWindow& window)
{
	this->initVariables();
	this->window = &window;
}

Shop::Shop()
{
	;
}

//Destructor
Shop::~Shop()
{
	delete this->window;
}

//Private functions
void Shop::initVariables()
{
	this->window = nullptr;
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
void Shop::draw()
{
	this->window->draw(this->shopTowers.getSpriteTower(0));
}

void Shop::drawClickedTower()
{
	sf::Vector2f mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*this->window));
	switch (this->getIsClicked()) {
	case 0:
		this->getShopTowers().getTower(0)->setPosition(sf::Vector2f(mousePositionFloat.x - 45.0f, mousePositionFloat.y - 45.0f));
		this->window->draw(this->getMapGridSprite());
		this->window->draw(this->getShopTowers().getTower(0)->getSprite());
		this->window->draw(this->getShopTowers().getTower(0)->getRange());
	}

}

void Shop::shopClicked()
{
	sf::Vector2f mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*this->window));

	if (this->shopTowers.getSpriteTower(0).getGlobalBounds().contains(mousePositionFloat)) {
		if (this->totalGold >= this->shopTowers.getTower(0)->getCost()) {
			if (getIsClicked() == 0) {
				changeIsClicked(-1);
			}else changeIsClicked(0);
			
		}
	}

}

void Shop::buy()
{
	sf::Vector2f mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*this->window));
	if (this->mapTiles.isValid(*this->window, mousePositionFloat)) {
		this->totalGold -= getCost(getIsClicked());
		//add to vector of towers, arguments - mouseposition, tower, 
		std::cout << totalGold << std::endl;
		changeIsClicked(-1);
	}else std::cout << "Tu tego nie postawisz cieciu" << std::endl;
}

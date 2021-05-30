#include "shop.h"

//Constructor
Shop::Shop(sf::RenderWindow& window, TowerContainer & towerContainer)
{
	this->initVariables();
	this->window = &window;
	this->towerContainer = &towerContainer;
}

Shop::Shop()
{
	;
}

//Destructor
Shop::~Shop()
{
}

//Private functions
void Shop::initVariables()
{
	this->window = nullptr;
	this->towerContainer = nullptr;
	this->totalGold = 1000;
	this->mapGridTexture.loadFromFile("mapGrid1.png");
	this->mapGrid.setTexture(this->mapGridTexture);
	this->initGoldLabel();
}

void Shop::initGoldLabel()
{
	this->goldLabel.setFont(getFont());
	this->goldLabel.setFillColor(sf::Color::Yellow);
	this->goldLabel.setOutlineColor(sf::Color::Black);
	this->goldLabel.setOutlineThickness(2);
	this->goldLabel.setCharacterSize(30);
	this->goldLabel.setString("$" + std::to_string(this->totalGold));
	this->goldLabel.setPosition(sf::Vector2f(1020.0f, 20.0f));
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
	this->window->draw(this->shopTowers.getOutlines(0));
	this->window->draw(this->shopTowers.getLabel(0));
	this->window->draw(this->goldLabel);
}

void Shop::drawClickedTower()
{
	sf::Vector2f mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*this->window));
	switch (this->getIsClicked()) {
	case 0:
		this->getShopTowers().getTower(0)->setPosition(sf::Vector2f(mousePositionFloat.x - 45.0f, mousePositionFloat.y - 45.0f));
		this->window->draw(this->getMapGridSprite());
		this->window->draw(this->getShopTowers().getTower(0)->getRange());
		this->window->draw(this->getShopTowers().getTower(0)->getSprite());
		break;
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

		this->goldLabel.setString("$" + std::to_string(this->totalGold));

		this->towerContainer->add(mousePositionFloat, getIsClicked());				//Add to container of towers
		changeIsClicked(-1);
	}
}

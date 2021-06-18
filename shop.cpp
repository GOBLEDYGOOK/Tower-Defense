#include "shop.h"

//Constructor
Shop::Shop(sf::RenderWindow& window, TowerContainer& towerContainer)
{
	this->initVariables();
	this->initGoldLabel();
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
	this->totalGold = 100;
	if (!this->mapGridTexture.loadFromFile("mapGrid1.png"))
	{
		MessageBox(0, "Error! mapGrid1.png doesnt exist", 0, 0);
		exit(0);
	}
	this->mapGrid.setTexture(this->mapGridTexture);
	
}

void Shop::initGoldLabel()
{
	this->goldLabel.setFont(getFont());
	this->goldLabel.setFillColor(sf::Color::Yellow);
	this->goldLabel.setOutlineColor(sf::Color::Black);
	this->goldLabel.setOutlineThickness(3);
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

int Shop::getTotalGold() const
{
	return this->totalGold;
}


//Public functions
void Shop::addGold(int gold)
{
	this->totalGold += gold;
	this->goldLabel.setString("$" + std::to_string(this->totalGold));
}

void Shop::removeGold(int gold)
{
	this->totalGold -= gold;
	this->goldLabel.setString("$" + std::to_string(this->totalGold));
}

void Shop::draw()
{
	for (int i = 0; i < 3; i++) {
		this->window->draw(this->shopTowers.getSpriteTower(i));
		this->window->draw(this->shopTowers.getOutlines(i));
		this->window->draw(this->shopTowers.getLabel(i));
		this->window->draw(this->shopTowers.getName(i));
	}
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
	case 1:
		this->getShopTowers().getTower(1)->setPosition(sf::Vector2f(mousePositionFloat.x - 45.0f, mousePositionFloat.y - 45.0f));
		this->window->draw(this->getMapGridSprite());
		this->window->draw(this->getShopTowers().getTower(1)->getRange());
		this->window->draw(this->getShopTowers().getTower(1)->getSprite());
		break;
	case 2:
		this->getShopTowers().getTower(2)->setPosition(sf::Vector2f(mousePositionFloat.x - 45.0f, mousePositionFloat.y - 45.0f));
		this->window->draw(this->getMapGridSprite());
		this->window->draw(this->getShopTowers().getTower(2)->getRange());
		this->window->draw(this->getShopTowers().getTower(2)->getSprite());
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
	if (this->shopTowers.getSpriteTower(1).getGlobalBounds().contains(mousePositionFloat)) {
		if (this->totalGold >= this->shopTowers.getTower(1)->getCost()) {
			if (getIsClicked() == 1) {
				changeIsClicked(-1);
			}
			else changeIsClicked(1);
		}
	}
	if (this->shopTowers.getSpriteTower(2).getGlobalBounds().contains(mousePositionFloat)) {
		if (this->totalGold >= this->shopTowers.getTower(2)->getCost()) {
			if (getIsClicked() == 2) {
				changeIsClicked(-1);
			}
			else changeIsClicked(2);
		}
	}
}

void Shop::buy()
{
	sf::Vector2f mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*this->window));
	if (this->mapTiles.isValid(*this->window, mousePositionFloat)) {
		this->totalGold -= getCost(getIsClicked());
		this->towerContainer->add(mousePositionFloat, getIsClicked());				//Add to container of towers
		changeIsClicked(-1);
	}
}

void Shop::reset()
{
	this->changeIsClicked(-1);
}

bool Shop::isTower(sf::RenderWindow & window, sf::Vector2f mousePositionFloat)
{
	return this->mapTiles.isTower(window, mousePositionFloat);
}

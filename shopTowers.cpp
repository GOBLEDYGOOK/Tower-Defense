#include "shopTowers.h"
//Constructor
ShopTowers::ShopTowers()
{
	this->initVariables();
}

//Destructor
ShopTowers::~ShopTowers()
{
	
}

//Private functions
void ShopTowers::initVariables()
{
	this->font.loadFromFile("arial.ttf");
	this->isClicked = -1;
	this->towers[0] = new TowerBasic();
	this->costs[0] = this->towers[0]->getCost();
	this->textureTowers[0] = this->towers[0]->getTexture();
	this->spriteTowers[0].setPosition(1020.0f, 330.0f);
	this->spriteTowers[0].setTexture(this->textureTowers[0]);
	this->outlines[0].setFillColor(sf::Color(0, 0, 0, 0));
	this->outlines[0].setOutlineThickness(2);
	this->outlines[0].setSize(sf::Vector2f(90.0f, 90.0f));
	this->outlines[0].setOutlineColor(sf::Color(0, 0, 0, 255));
	this->outlines[0].setPosition(1020.0f, 330.0f);
	this->label[0].setFont(this->font);
	this->label[0].setFillColor(sf::Color::Yellow);
	this->label[0].setOutlineColor(sf::Color::Black);
	this->label[0].setOutlineThickness(1);
	this->label[0].setCharacterSize(12);
	this->label[0].setString("$" + std::to_string(costs[0]));
	this->label[0].setPosition(sf::Vector2f(this->spriteTowers[0].getGlobalBounds().left + this->label[0].getLocalBounds().width, this->spriteTowers[0].getGlobalBounds().top + 76 ));
}



sf::Sprite ShopTowers::getSpriteTower(size_t i) const
{
	return this->spriteTowers[i];
}

sf::RectangleShape ShopTowers::getOutlines(size_t i) const
{
	return this->outlines[i];
}

int ShopTowers::getCost(size_t i) const
{
	return this->costs[i];
}

sf::Text ShopTowers::getLabel(size_t i) const
{
	return this->label[i];
}

sf::Font& ShopTowers::getFont()
{
	return this->font;
}

Tower* ShopTowers::getTower(size_t i) const
{
	return this->towers[i];
}


const int ShopTowers::getNumberOfTowers() const
{
	return this->numberOfTowers;
}

int ShopTowers::getIsClicked() const
{
	return this->isClicked;
}


//Public functions
void ShopTowers::changeIsClicked(int i)
{
	this->isClicked = i;
	
}
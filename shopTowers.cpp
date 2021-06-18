#include "shopTowers.h"
//Constructor
ShopTowers::ShopTowers()
{
	this->initVariables();
	this->initTowers();
	this->initLabels();
	this->initNames();
}

//Destructor
ShopTowers::~ShopTowers()
{
	;
}

//Private functions
void ShopTowers::initVariables()
{
	if (!this->font.loadFromFile("arial.ttf"))
	{
		MessageBox(0, "Error! arial.ttf doesnt exist", 0, 0);
		exit(0);
	}
	this->isClicked = -1;
}

void ShopTowers::initTowers()
{
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

	this->towers[1] = new TowerTripleShot();
	this->costs[1] = this->towers[1]->getCost();
	this->textureTowers[1] = this->towers[1]->getTexture();
	this->spriteTowers[1].setPosition(1140.0f, 330.0f);
	this->spriteTowers[1].setTexture(this->textureTowers[1]);
	this->outlines[1].setFillColor(sf::Color(0, 0, 0, 0));
	this->outlines[1].setOutlineThickness(2);
	this->outlines[1].setSize(sf::Vector2f(90.0f, 90.0f));
	this->outlines[1].setOutlineColor(sf::Color(0, 0, 0, 255));
	this->outlines[1].setPosition(1140.0f, 330.0f);

	this->towers[2] = new TowerSniper();
	this->costs[2] = this->towers[2]->getCost();
	this->textureTowers[2] = this->towers[2]->getTexture();
	this->spriteTowers[2].setPosition(1080.0f, 450.0f);
	this->spriteTowers[2].setTexture(this->textureTowers[2]);
	this->outlines[2].setFillColor(sf::Color(0, 0, 0, 0));
	this->outlines[2].setOutlineThickness(2);
	this->outlines[2].setSize(sf::Vector2f(90.0f, 90.0f));
	this->outlines[2].setOutlineColor(sf::Color(0, 0, 0, 255));
	this->outlines[2].setPosition(1080.0f, 450.0f);
}

void ShopTowers::initLabels()
{
	this->label[0].setFont(this->font);
	this->label[0].setFillColor(sf::Color::Yellow);
	this->label[0].setOutlineColor(sf::Color::Black);
	this->label[0].setOutlineThickness(1);
	this->label[0].setCharacterSize(12);
	this->label[0].setString("$" + std::to_string(costs[0]));
	this->label[0].setPosition(sf::Vector2f(this->spriteTowers[0].getGlobalBounds().left + this->label[0].getLocalBounds().width, this->spriteTowers[0].getGlobalBounds().top + 76));

	this->label[1].setFont(this->font);
	this->label[1].setFillColor(sf::Color::Yellow);
	this->label[1].setOutlineColor(sf::Color::Black);
	this->label[1].setOutlineThickness(1);
	this->label[1].setCharacterSize(12);
	this->label[1].setString("$" + std::to_string(costs[1]));
	this->label[1].setPosition(sf::Vector2f(this->spriteTowers[1].getGlobalBounds().left + this->label[1].getLocalBounds().width, this->spriteTowers[1].getGlobalBounds().top + 76));

	this->label[2].setFont(this->font);
	this->label[2].setFillColor(sf::Color::Yellow);
	this->label[2].setOutlineColor(sf::Color::Black);
	this->label[2].setOutlineThickness(1);
	this->label[2].setCharacterSize(12);
	this->label[2].setString("$" + std::to_string(costs[2]));
	this->label[2].setPosition(sf::Vector2f(this->spriteTowers[2].getGlobalBounds().left + this->label[2].getLocalBounds().width, this->spriteTowers[2].getGlobalBounds().top + 76));
}

void ShopTowers::initNames()
{
	this->name[0].setFont(this->font);
	this->name[0].setFillColor(sf::Color::Black);
	this->name[0].setCharacterSize(15);
	this->name[0].setString("Basic");
	this->name[0].setPosition(sf::Vector2f(this->spriteTowers[0].getGlobalBounds().left + this->spriteTowers[0].getLocalBounds().width / 2 - this->name[0].getLocalBounds().width / 2, this->spriteTowers[0].getGlobalBounds().top - 20));

	this->name[1].setFont(this->font);
	this->name[1].setFillColor(sf::Color::Black);
	this->name[1].setCharacterSize(15);
	this->name[1].setString("Triple Shot");
	this->name[1].setPosition(sf::Vector2f(this->spriteTowers[1].getGlobalBounds().left + this->spriteTowers[1].getLocalBounds().width / 2 - this->name[1].getLocalBounds().width / 2, this->spriteTowers[1].getGlobalBounds().top - 20));

	this->name[2].setFont(this->font);
	this->name[2].setFillColor(sf::Color::Black);
	this->name[2].setCharacterSize(15);
	this->name[2].setString("Sniper");
	this->name[2].setPosition(sf::Vector2f(this->spriteTowers[2].getGlobalBounds().left + this->spriteTowers[2].getLocalBounds().width / 2 - this->name[2].getLocalBounds().width / 2, this->spriteTowers[2].getGlobalBounds().top - 20));
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

sf::Text ShopTowers::getName(size_t i) const
{
	return this->name[i];
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
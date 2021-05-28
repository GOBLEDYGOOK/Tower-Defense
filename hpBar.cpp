#include "hpBar.h"

//Private functions
void HpBar::initHp(sf::Vector2f position)
{
	this->hp.setSize(sf::Vector2f(60.0f, 8.0f));
	this->hp.setFillColor(sf::Color::Red);
	this->hp.setOutlineColor(sf::Color::Black);
	this->hp.setOutlineThickness(1);
	this->hp.setPosition(sf::Vector2f(position.x + 15, position.y + 80));
}

//Constructor
HpBar::HpBar(int hp, sf::Vector2f position)
{
	this->initHp(position);
	this->enemyHp = hp;
}

//Destructor
HpBar::~HpBar()
{
}

//Public functions
void HpBar::update(int hp, sf::Vector2f position)
{
	this->hp.setPosition(sf::Vector2f(position.x + 15, position.y + 80));
	if (hp > 0) {
		this->hp.setSize(sf::Vector2f(60.0f * (float(hp) / float(this->enemyHp)), 8.0f));
	}
	
}

void HpBar::draw(sf::RenderWindow & window)
{
	window.draw(this->hp);
}

void HpBar::move(float x, float y)
{
	this->hp.move(x, y);
}

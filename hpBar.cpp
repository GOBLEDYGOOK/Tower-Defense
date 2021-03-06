#include "hpBar.h"

//Private functions
void HpBar::initHp()
{
	this->hp.setFillColor(sf::Color::Red);
	this->frame.setOutlineColor(sf::Color::Black);
	this->frame.setFillColor(sf::Color(0, 0, 0, 0));
	this->frame.setOutlineThickness(2);
}

//Constructor
HpBar::HpBar(int hp)
{
	this->initHp();
	this->fullHp = hp;
}

//Destructor
HpBar::~HpBar()
{
}

//Public functions
void HpBar::updateEnemy(int hp, sf::Vector2f position)
{
	this->hp.setPosition(sf::Vector2f(position.x + 15, position.y + 80));
	if (hp > 0) {
		this->hp.setSize(sf::Vector2f(60.0f * (float(hp) / float(this->fullHp)), 8.0f));
	}
	
}

void HpBar::updateBase(int hp)
{
	if (hp > 0) {
		this->hp.setSize(sf::Vector2f(230.0f * (float(hp) / float(this->fullHp)), 20.0f));
	}
}

void HpBar::draw(sf::RenderWindow & window)
{
	window.draw(this->frame);
	window.draw(this->hp);
}

void HpBar::move(float x, float y)
{
	this->frame.move(x, y);
	this->hp.move(x, y);
}

void HpBar::setPosition(sf::Vector2f position)
{
	this->frame.setPosition(position);
	this->hp.setPosition(position);
}

void HpBar::setSize(sf::Vector2f size)
{
	this->frame.setSize(size);
	this->hp.setSize(size);
}

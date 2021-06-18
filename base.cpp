#include "base.h"
//Private functions
void Base::initVariables()
{
	this->hp = 100;
	this->hpBar = new HpBar(this->hp);
	this->hpBar->setPosition(sf::Vector2f(1010.0f, 850.0f));
	this->hpBar->setSize(sf::Vector2f(230.0f, 20.0f));
}

//Constructor
Base::Base()
{
	this->initVariables();
}

//Destructor
Base::~Base()
{
	delete this->hpBar;
}

int Base::getHp() const
{
	return this->hp;
}

//Public functions
void Base::update()
{
	this->hpBar->updateBase(this->hp);
}

void Base::draw(sf::RenderWindow & window)
{
	this->hpBar->draw(window);
}

void Base::receiveDamage(int dmg)
{
	this->hp -= dmg;
}

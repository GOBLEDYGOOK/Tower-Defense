#pragma once
#include "hpBar.h"

class Base
{
	//Private variables
	HpBar* hpBar;
	int hp;

	//Private functions
	void initVariables();
public:
	//Constructors /Destructors
	Base();
	~Base();

	//Accessors
	int getHp()const;

	//public functions
	void update();
	void draw(sf::RenderWindow& window);
	void receiveDamage(int dmg);


};


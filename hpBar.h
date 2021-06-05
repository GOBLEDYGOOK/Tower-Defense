#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class HpBar
{
	//Private variables
	sf::RectangleShape hp;
	sf::RectangleShape frame;
	int fullHp;

	//Private functions
	void initHp();
public:
	//Constructors /Destructors
	HpBar(int hp);
	~HpBar();

	//Public functions
	void updateEnemy(int hp, sf::Vector2f position);
	void updateBase(int hp);
	
	void draw(sf::RenderWindow& window);
	void move(float x, float y);
	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);

};


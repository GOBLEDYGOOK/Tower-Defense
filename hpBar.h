#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class HpBar
{
	//Private variables
	sf::RectangleShape hp;
	int enemyHp;

	//Private functions
	void initHp(sf::Vector2f position);
public:
	//Constructors /Destructors
	HpBar(int hp, sf::Vector2f position);
	~HpBar();

	//Public functions
	void update(int hp, sf::Vector2f position);
	void draw(sf::RenderWindow& window);
	void move(float x, float y);

};


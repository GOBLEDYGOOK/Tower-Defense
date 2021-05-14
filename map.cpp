#include "map.h"

//Constructors /Destructors
Map::Map(sf::VideoMode videoMode)
{
	this->initVariables(videoMode);
}

Map::~Map()
{
}



//Private functions
void Map::initVariables(sf::VideoMode videoMode)
{
	this->mapTexture.loadFromFile("map.png");
	this->map.setTexture(this->mapTexture);
	this->videoMode = videoMode;
	enemy.setPosition(270.0f, -90.0f);
}

//Public functions
void Map::draw(sf::RenderWindow& window)
{
	sf::CircleShape circle;
	circle.setRadius(180);
	circle.setOutlineColor(sf::Color::Color(0, 0, 255, 100));
	circle.setOutlineThickness(3);
	circle.setPosition(270,90);
	circle.setFillColor(sf::Color::Color(0, 0, 255, 50));
	sf::Texture tmp;
	

	tmp.loadFromFile("mapGrid1.png");
	sf::Sprite tmp1(tmp);
	enemyT.loadFromFile("enemyFast.png");
	enemy.setTexture(enemyT);
	window.draw(this->map);
	if(enemy.getPosition().y==270)enemy.setPosition(enemy.getPosition().x +2, enemy.getPosition().y );
	else
	enemy.setPosition(enemy.getPosition().x, enemy.getPosition().y +2);
	//std::cout << enemy.getGlobalBounds().left<< " " << enemy.getGlobalBounds().width << std::endl;
	window.draw(enemy);
	window.draw(tmp1);
	window.draw(circle);
	
	float dx = (enemy.getPosition().x + (enemy.getGlobalBounds().width / 2)) - (circle.getPosition().x + (circle.getGlobalBounds().width / 2));
	float dy = (enemy.getPosition().y + (enemy.getGlobalBounds().height / 2)) - (circle.getPosition().y + (circle.getGlobalBounds().height / 2));
	float d = std::sqrt(dx * dx + dy * dy);
	if (d<=((enemy.getGlobalBounds().width /2)+ circle.getGlobalBounds().width / 2)) {
		
		std::cout << "kolizja" << std::endl;
	}
	
}



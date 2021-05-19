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

void Map::initMap()
{
	
}

//Public functions
void Map::draw(sf::RenderWindow& window)
{
	sf::CircleShape circle;
	circle.setRadius(180);
	circle.setOutlineColor(sf::Color::Color(0, 0, 255, 100));
	circle.setOutlineThickness(3);
	
	circle.setFillColor(sf::Color::Color(0, 0, 255, 50));
	
	sf::RectangleShape rect;

	int tmp2 = circle.getRadius();
	
	rect.setPosition(270, 360);
	circle.setPosition(enemy.getPosition().x - circle.getRadius()/2 - 45, enemy.getPosition().y - circle.getRadius() / 2 - 45); //Ustawienie range wzgledem wiezy
	rect.setSize(sf::Vector2f(90.0f, 90.0f));
	rect.setFillColor(sf::Color::Color(255, 0, 0, 100));
	
	
	enemyT.loadFromFile("enemyFast.png");
	enemy.setTexture(enemyT);
	window.draw(this->map);
	
	if(enemy.getPosition().y>=270.0f)enemy.setPosition(enemy.getPosition().x + 1.0f, enemy.getPosition().y );
	else
	enemy.setPosition(enemy.getPosition().x, enemy.getPosition().y + 1.0f);
	//std::cout << enemy.getGlobalBounds().left<< " " << enemy.getGlobalBounds().width << std::endl;
	window.draw(enemy);
	
	window.draw(circle);
	window.draw(rect);
	float dx = (enemy.getPosition().x + (enemy.getGlobalBounds().width / 2)) - (circle.getPosition().x + (circle.getGlobalBounds().width / 2));
	float dy = (enemy.getPosition().y + (enemy.getGlobalBounds().height / 2)) - (circle.getPosition().y + (circle.getGlobalBounds().height / 2));
	float d = std::sqrt(dx * dx + dy * dy);
	if (d<=((enemy.getGlobalBounds().width /2)+ circle.getGlobalBounds().width / 2)) {
		
		//std::cout << "dupa" << std::endl;
	}
	
}



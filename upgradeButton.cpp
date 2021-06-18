#include "upgradeButton.h"

//Private functions
void UpgradeButton::initVariables()
{
	if (!this->font.loadFromFile("arial.ttf"))
	{
		MessageBox(0, "Error! arial.ttf doesnt exist", 0, 0);
		exit(0);
	}
	this->upgradeCost.setFont(this->font);
	this->upgradeCost.setCharacterSize(12);
	this->upgradeCost.setFillColor(sf::Color::Yellow);
	this->upgradeCost.setOutlineColor(sf::Color::Black);
	this->upgradeCost.setOutlineThickness(1);
	if (!this->buttonTexture.loadFromFile("upgradeButton.png"))
	{
		MessageBox(0, "Error! arial.ttf doesnt exist", 0, 0);
		exit(0);
	}
	this->buttonSprite.setTexture(this->buttonTexture);
}

//Constructor
UpgradeButton::UpgradeButton()
{
	this->initVariables();
}

//Destructor
UpgradeButton::~UpgradeButton()
{
}

sf::Sprite UpgradeButton::getButtonSprite() const
{
	return this->buttonSprite;
}

//Public functions
void UpgradeButton::update()
{

}

void UpgradeButton::draw(sf::RenderWindow & window)
{
	window.draw(this->buttonSprite);
	window.draw(this->upgradeCost);
}

void UpgradeButton::setCost(int cost)
{
	this->upgradeCost.setString("$" + std::to_string(cost));
	this->upgradeCost.setPosition(this->upgradeCost.getPosition());
}

void UpgradeButton::setPosition(sf::Vector2f position)
{
	if (position.y == 0 && position.x == 900) {
		this->buttonSprite.setPosition(sf::Vector2f(position.x + 55, position.y + 110));
		this->upgradeCost.setPosition(sf::Vector2f(position.x + 55, position.y + 135));
	}
	else if (position.x == 900) {
		this->buttonSprite.setPosition(sf::Vector2f(position.x + 55, position.y - 40));
		this->upgradeCost.setPosition(sf::Vector2f(position.x + 55, position.y - 15));
	}
	else if (position.y == 0) {
		this->buttonSprite.setPosition(sf::Vector2f(position.x + 115, position.y + 110));
		this->upgradeCost.setPosition(sf::Vector2f(position.x + 115, position.y + 135));
	}
	else {
		this->buttonSprite.setPosition(sf::Vector2f(position.x + 115, position.y - 40));
		this->upgradeCost.setPosition(sf::Vector2f(position.x + 115, position.y - 15));
	}
}

bool UpgradeButton::contains(sf::Vector2f mousePosition)
{
	if (this->buttonSprite.getGlobalBounds().contains(mousePosition)) return true;
	return false;
}

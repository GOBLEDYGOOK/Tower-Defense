#include "wave.h"

//Private functions
void Wave::initEnemyContainer(int numberOfBasic, int numberOfFast, int numberOfTank) // totalNumberOfEnemies = numberOfBasic + numberOfFast + numberOfTank
{
	srand(time(NULL));
	int i;
	Enemy* toAdd = nullptr;;
	while (numberOfBasic + numberOfFast + numberOfTank) {
		toAdd = nullptr;
		i = rand() % 3;

		switch (i) {
		case 0:
			if (numberOfBasic != 0) {
				
				numberOfBasic--;
				toAdd = new EnemyBasic();
			}
			break;
		case 1:
			if (numberOfFast != 0) {
				
				numberOfFast--;
				toAdd = new EnemyFast();
			}
			break;
		case 2:
			if (numberOfTank != 0) {
				
				numberOfTank--;
				toAdd = new EnemyTank();
			}
			break;
		}
		if (toAdd != nullptr) {
			this->enemyContainer.push_back(toAdd);
		}
	}
	
	
}

//Constructor
Wave::Wave(int numberOfBasic, int numberOfFast, int numberOfTank)  // totalNumberOfEnemies = numberOfBasic + numberOfFast + numberOfTank
{
		this->initEnemyContainer(numberOfBasic, numberOfFast, numberOfTank);
}

//Destructor
Wave::~Wave() {

}

//Public functions
int Wave::update(sf::RenderWindow& window, Base& base)
{
	int goldToAdd = 0;
	std::vector<std::vector<Enemy*>::iterator> enemiesToDelete;
	for (auto itr = this->enemyContainer.begin(); itr != this->enemyContainer.end(); itr++) {
		if ((*itr)->getIsStarted() && itr != this->enemyContainer.end() - 1 && (*itr)->getEnemySprite().getPosition().y == 0)(*(itr + 1))->startEnemy();
		if ((*itr)->getIsStarted()) {
			if ((*itr)->getEnemySprite().getPosition().y == 900) {
				base.receiveDamage((*itr)->getDamage());
				enemiesToDelete.push_back(itr);
			}
			else if ((*itr)->getIsDead()) {
				goldToAdd += (*itr)->getGold();
				enemiesToDelete.push_back(itr);
			}
			(*itr)->update(window);
		}
	}
	for (size_t i = 0; i < enemiesToDelete.size(); i++) {
		this->enemyContainer.erase(enemiesToDelete.back());
		enemiesToDelete.pop_back();
	}
	
	
	
	return goldToAdd;
}

void Wave::draw(sf::RenderWindow & window)
{
	for (auto itr = this->enemyContainer.begin(); itr != this->enemyContainer.end(); itr++) {
		if ((*itr)->getIsStarted()) {
			(*itr)->draw(window);
		}
	}
}

void Wave::startWave() {
	(*this->enemyContainer.begin())->startEnemy();
}

std::vector<Enemy *>::iterator Wave::begin()
{
	return enemyContainer.begin();
}

std::vector<Enemy *>::iterator Wave::end()
{
	return enemyContainer.end();
}

bool Wave::empty()
{
	return this->enemyContainer.empty();
}

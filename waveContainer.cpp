#include "waveContainer.h"

//Private functions

void WaveContainer::initWaves()
{
	int wave = 1;
	Wave * toAdd = nullptr;
	while (wave <= this->maxNumberOfWaves) {
		toAdd = nullptr;
		switch (wave) {
		case 1:
			toAdd = new Wave(0, 2, 0);								//int numberOfBasic, int numberOfFast, int numberOfTank
			this->waveContainer.push_back(toAdd);
			break;
		case 2:
			toAdd = new Wave(0, 0, 0);								//int numberOfBasic, int numberOfFast, int numberOfTank
			this->waveContainer.push_back(toAdd);
			break;
		case 3:
			toAdd = new Wave(0, 0, 0);								//int numberOfBasic, int numberOfFast, int numberOfTank
			this->waveContainer.push_back(toAdd);
			break;
		case 4:
			toAdd = new Wave(0, 0, 0);								//int numberOfBasic, int numberOfFast, int numberOfTank
			this->waveContainer.push_back(toAdd);
			break;
		case 5:
			toAdd = new Wave(0, 0, 0);								//int numberOfBasic, int numberOfFast, int numberOfTank
			this->waveContainer.push_back(toAdd);
			break;
		case 6:
			toAdd = new Wave(0, 0, 0);								//int numberOfBasic, int numberOfFast, int numberOfTank
			this->waveContainer.push_back(toAdd);
			break;
		case 7:
			toAdd = new Wave(0, 0, 0);								//int numberOfBasic, int numberOfFast, int numberOfTank
			this->waveContainer.push_back(toAdd);
			break;
		case 8:
			toAdd = new Wave(0, 0, 0);								//int numberOfBasic, int numberOfFast, int numberOfTank
			this->waveContainer.push_back(toAdd);
			break;
		case 9:
			toAdd = new Wave(0, 0, 0);								//int numberOfBasic, int numberOfFast, int numberOfTank
			this->waveContainer.push_back(toAdd);
			break;
		case 10:
			toAdd = new Wave(1, 0, 0);								//int numberOfBasic, int numberOfFast, int numberOfTank
			this->waveContainer.push_back(toAdd);
			break;
		}
		wave++;

	}
}

void WaveContainer::initCurrentWave()
{
	this->currentWave = 1;
}

//Constructors
WaveContainer::WaveContainer()
{
	this->initCurrentWave();
	this->initWaves();
}

//Destructor
WaveContainer::~WaveContainer()
{
}

//Accessors
int WaveContainer::getCurrentWave() const
{
	return this->currentWave;
}

int WaveContainer::getMaxNumberOfWaves() const
{
	return this->maxNumberOfWaves;
}

//Public functions
int WaveContainer::update(sf::RenderWindow & window, Base& base)
{
	if (!this->waveContainer.empty() && (*this->waveContainer.begin())->empty()) {
		this->currentWave++;
		this->waveContainer.erase(this->waveContainer.begin());
	}
	if (!this->waveContainer.empty())return (*this->waveContainer.begin())->update(window, base);
	return 0;
}

void WaveContainer::draw(sf::RenderWindow & window)
{
	if (!this->waveContainer.empty())(*this->waveContainer.begin())->draw(window);
}

void WaveContainer::startNextWave()
{
	if (!this->waveContainer.empty()) (*this->waveContainer.begin())->startWave();
}

Wave* WaveContainer::front()
{
	if (!this->waveContainer.empty()) {
		return this->waveContainer.front();
	}
}

bool WaveContainer::empty() const
{
	return this->waveContainer.empty();
}

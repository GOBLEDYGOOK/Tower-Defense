#pragma once
#include "wave.h"

/*
		Class which store all waves of the enemies
*/

class WaveContainer
{
	//Private variables
	static const int maxNumberOfWaves = 10;
	std::vector <Wave*> waveContainer;
	int currentWave;
	
	//Private functions
	void initWaves();
	void initCurrentWave();
public:
	//Constructors / Destructors
	WaveContainer();
	~WaveContainer();


	//Accessors
	int getCurrentWave() const;
	int getMaxNumberOfWaves() const;

	//Public functions
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void startNextWave();
	Wave* front();
};


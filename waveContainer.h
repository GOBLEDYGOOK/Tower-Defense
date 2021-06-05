#pragma once
#include "wave.h"


/*
		Class which stores all waves of the enemies
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
	bool empty() const;

	//Public functions
	int update(sf::RenderWindow& window, Base& base); 
	void draw(sf::RenderWindow& window);
	void startNextWave();
	Wave* front();
	
};

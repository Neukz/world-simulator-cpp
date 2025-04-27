#pragma once
#include "Organism.h"

class Plant : public Organism {
private:
	// % chance (0-100)
	static const int SowingProbability = 10;

	virtual std::string getSpecies() const = 0;

public:
	Plant(int strength, std::string symbol, int x, int y, World* world);

	virtual void action() override;
	virtual void collision(Organism* other) override;
};
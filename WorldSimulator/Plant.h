#pragma once
#include "Organism.h"

class Plant : public Organism {
private:
	// % chance (0-100)
	static const int SowingProbability = 10;

	virtual std::string toString() const = 0;
	virtual Organism* createNewInstance(int x, int y) = 0;
	void sow();

public:
	Plant(int strength, char symbol, int x, int y, World* world);

	virtual void action() override;
	virtual void collision(Organism* other) override;
};
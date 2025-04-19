#pragma once
#include "Organism.h"

class Plant : public Organism {
private:
	virtual std::string toString() const = 0;

public:
	Plant(int strength, char symbol, int x, int y, World* world);

	virtual void action() override;
	virtual Organism* collision(Organism* other) override;
};

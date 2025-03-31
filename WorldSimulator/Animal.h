#pragma once
#include "Organism.h"

class Animal : public Organism {
public:
	Animal(int strength, int initiative, char symbol, int x, int y, World* world);

	virtual void action() override;
	virtual void collision(Organism* other) override;
};
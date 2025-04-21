#pragma once
#include "Organism.h"

class Animal : public Organism {
private:
	virtual std::string toString() const = 0;
	virtual Organism* createNewInstance(int x, int y) = 0;
	void breed(Organism* other);

public:
	Animal(int strength, int initiative, char symbol, int x, int y, World* world);

	virtual void action() override;
	virtual void collision(Organism* other) override;
};
#pragma once
#include "Organism.h"

class Animal : public Organism {
protected:
	virtual std::string getName() const = 0;

public:
	Animal(int strength, int initiative, char symbol, int x, int y, World* world);

	virtual void action() override;
	virtual Organism* collision(Organism* other) override;

	void breed() const;
};
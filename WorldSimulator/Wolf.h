#pragma once
#include "Animal.h"

class Wolf : public Animal {
private:
	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;

public:
	Wolf(int x, int y, World* world);
};
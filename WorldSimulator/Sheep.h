#pragma once
#include "Animal.h"

class Sheep : public Animal {
private:
	static const int Strength = 4;
	static const int Initiative = 4;
	static const char Symbol = 'S';

	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;

public:
	Sheep(int x, int y, World* world);
};
#pragma once
#include "Animal.h"

class Wolf : public Animal {
private:
	static const int Strength = 9;
	static const int Initiative = 5;
	static const char Symbol = 'W';

	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;

public:
	Wolf(int x, int y, World* world);
};
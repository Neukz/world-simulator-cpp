#pragma once
#include "Animal.h"

class Wolf : public Animal {
private:
	static const int Strength = 9;
	static const int Initiative = 5;
	static const std::string Symbol;
	static const std::string Species;

	static bool registered;

	std::string getSpecies() const override;

public:
	Wolf(int x, int y, World* world);
};
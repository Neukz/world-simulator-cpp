#pragma once
#include "Animal.h"

class Sheep : public Animal {
private:
	static const int Strength = 4;
	static const int Initiative = 4;
	static const std::string Symbol;
	static const std::string Species;

	static bool registered;

	std::string getSpecies() const override;

public:
	Sheep(int x, int y, World* world);
};
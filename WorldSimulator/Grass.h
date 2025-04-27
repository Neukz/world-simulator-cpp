#pragma once
#include "Plant.h"

class Grass : public Plant {
private:
	static const int Strength = 0;
	static const std::string Symbol;
	static const std::string Species;

	static bool registered;

	std::string getSpecies() const override;

public:
	Grass(int x, int y, World* world);
};
#pragma once
#include "Plant.h"

class Belladonna : public Plant {
private:
	static const int Strength = 99;
	static const std::string Symbol;
	static const std::string Species;

	static bool registered;

	std::string getSpecies() const override;

public:
	Belladonna(int x, int y, World* world);

	void collision(Organism* other) override;
};
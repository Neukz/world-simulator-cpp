#pragma once
#include "Plant.h"

class Guarana : public Plant {
private:
	static const int Strength = 0;
	static const std::string Symbol;
	static const std::string Species;

	static bool registered;

	std::string getSpecies() const override;
	void boostEater(Organism* eater);

public:
	Guarana(int x, int y, World* world);

	void collision(Organism* other) override;
};
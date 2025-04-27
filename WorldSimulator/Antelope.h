#pragma once
#include "Animal.h"

class Antelope : public Animal {
private:
	static const int Strength = 4;
	static const int Initiative = 4;
	static const std::string Symbol;
	static const std::string Species;

	static bool registered;

	std::string getSpecies() const override;
	void escape();

public:
	Antelope(int x, int y, World* world);

	void action() override;
	void collision(Organism* other) override;
};
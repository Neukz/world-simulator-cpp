#pragma once
#include "Plant.h"

class Grass : public Plant {
private:
	static const int Strength = 0;
	static const char Symbol = 'g';

	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;

public:
	Grass(int x, int y, World* world);
};
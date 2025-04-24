#pragma once
#include "Plant.h"

class Grass : public Plant {
private:
	static const int Strength = 0;
	static const char Symbol = 'g';

	static bool registered;

	std::string toString() const override;

public:
	Grass(int x, int y, World* world);
};
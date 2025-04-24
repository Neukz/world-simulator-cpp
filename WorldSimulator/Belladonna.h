#pragma once
#include "Plant.h"

class Belladonna : public Plant {
private:
	static const int Strength = 99;
	static const char Symbol = 'b';

	static bool registered;

	std::string toString() const override;

public:
	Belladonna(int x, int y, World* world);

	void collision(Organism* other) override;
};
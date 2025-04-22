#pragma once
#include "Plant.h"

class Belladonna : public Plant {
private:
	static const int Strength = 99;
	static const char Symbol = 'b';

	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;

public:
	Belladonna(int x, int y, World* world);

	void collision(Organism* other) override;
};
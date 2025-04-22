#pragma once
#include "Plant.h"

class SowThistle : public Plant {
private:
	static const int Strength = 0;
	static const char Symbol = 's';

	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;

public:
	SowThistle(int x, int y, World* world);

	void action() override;
};
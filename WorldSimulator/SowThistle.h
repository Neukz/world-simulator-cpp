#pragma once
#include "Plant.h"

class SowThistle : public Plant {
private:
	static const int Strength = 0;
	static const std::string Symbol;

	static bool registered;

	std::string toString() const override;

public:
	SowThistle(int x, int y, World* world);

	void action() override;
};
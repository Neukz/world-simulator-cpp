#pragma once
#include "Plant.h"

class SowThistle : public Plant {
private:
	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;

public:
	SowThistle(int x, int y, World* world);

	void action() override;
};
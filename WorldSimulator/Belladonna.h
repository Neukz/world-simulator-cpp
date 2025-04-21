#pragma once
#include "Plant.h"

class Belladonna : public Plant {
private:
	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;

public:
	Belladonna(int x, int y, World* world);

	void collision(Organism* other) override;
};
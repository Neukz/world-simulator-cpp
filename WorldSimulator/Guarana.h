#pragma once
#include "Plant.h"

class Guarana : public Plant {
private:
	static const int Strength = 0;
	static const char Symbol = 'u';

	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;
	void boostEater(Organism* eater);

public:
	Guarana(int x, int y, World* world);

	void collision(Organism* other) override;
};
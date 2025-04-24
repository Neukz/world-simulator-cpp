#pragma once
#include "Animal.h"

class Antelope : public Animal {
private:
	static const int Strength = 4;
	static const int Initiative = 4;
	static const char Symbol = 'A';

	static bool registered;

	std::string toString() const override;
	void escape();

public:
	Antelope(int x, int y, World* world);

	void action() override;
	void collision(Organism* other) override;
};
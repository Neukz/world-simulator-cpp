#pragma once
#include "Animal.h"

class Fox : public Animal {
private:
	static const int Strength = 3;
	static const int Initiative = 7;
	static const char Symbol = 'F';

	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;
	bool encounteredStrongerOrganism();

public:
	Fox(int x, int y, World* world);

	void action() override;
};
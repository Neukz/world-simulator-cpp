#pragma once
#include "Animal.h"

class Turtle : public Animal {
private:
	static const int Strength = 2;
	static const int Initiative = 1;
	static const char Symbol = 'T';

	static bool registered;

	std::string toString() const override;
	void deflectAttack(Organism* attacker) const;

public:
	Turtle(int x, int y, World* world);

	void action() override;
	void collision(Organism* other) override;
};
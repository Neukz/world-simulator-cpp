#pragma once
#include "Animal.h"

class Turtle : public Animal {
private:
	static const int Strength = 2;
	static const int Initiative = 1;
	static const char Symbol = 'T';

	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;
	void deflectAttack(Organism* attacker) const;

public:
	Turtle(int x, int y, World* world);

	void action() override;
	void collision(Organism* other) override;
};
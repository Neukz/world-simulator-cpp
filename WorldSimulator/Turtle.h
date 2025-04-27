#pragma once
#include "Animal.h"

class Turtle : public Animal {
private:
	static const int Strength = 2;
	static const int Initiative = 1;
	static const std::string Symbol;
	static const std::string Species;

	static bool registered;

	std::string getSpecies() const override;
	void deflectAttack(Organism* attacker) const;

public:
	Turtle(int x, int y, World* world);

	void action() override;
	void collision(Organism* other) override;
};
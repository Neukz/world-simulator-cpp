#pragma once
#include "Animal.h"

class Turtle : public Animal {
private:
	void deflectAttack(Organism* attacker) const;

protected:
	std::string getName() const override;

public:
	Turtle(int x, int y, World* world);

	void action() override;
	Organism* collision(Organism* other) override;
};
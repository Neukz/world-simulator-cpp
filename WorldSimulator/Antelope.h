#pragma once
#include "Animal.h"

class Antelope : public Animal {
private:
	std::string toString() const override;
	void escape();

public:
	Antelope(int x, int y, World* world);

	void action() override;
	Organism* collision(Organism* other) override;
};
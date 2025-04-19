#pragma once
#include "Animal.h"

class Antelope : public Animal {
private:
	void escape();

protected:
	std::string getName() const override;

public:
	Antelope(int x, int y, World* world);

	void action() override;
	Organism* collision(Organism* other) override;
};
#pragma once
#include "Animal.h"

class Fox : public Animal {
private:
	std::string toString() const override;
	bool encounteredStrongerOrganism();

public:
	Fox(int x, int y, World* world);

	void action() override;
};
#pragma once
#include "Animal.h"

class Fox : public Animal {
private:
	bool encounteredStrongerOrganism();

public:
	Fox(int x, int y, World* world);

	void action() override;
};
#pragma once
#include "Animal.h"

class Fox : public Animal {
private:
	bool encounteredStrongerOrganism();

protected:
	std::string getName() const override;

public:
	Fox(int x, int y, World* world);

	void action() override;
};
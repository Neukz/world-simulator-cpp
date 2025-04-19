#pragma once
#include "Animal.h"

class Sheep : public Animal {
protected:
	std::string getName() const override;

public:
	Sheep(int x, int y, World* world);
};
#pragma once
#include "Animal.h"

class Sheep : public Animal {
private:
	std::string toString() const override;

public:
	Sheep(int x, int y, World* world);
};
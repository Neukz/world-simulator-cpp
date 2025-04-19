#pragma once
#include "Animal.h"

class Wolf : public Animal {
private:
	std::string toString() const override;

public:
	Wolf(int x, int y, World* world);
};
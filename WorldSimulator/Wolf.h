#pragma once
#include "Animal.h"

class Wolf : public Animal {
protected:
	std::string getName() const override;

public:
	Wolf(int x, int y, World* world);
};
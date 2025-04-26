#pragma once
#include "Animal.h"

class Sheep : public Animal {
private:
	static const int Strength = 4;
	static const int Initiative = 4;
	static const std::string Symbol;

	static bool registered;

	std::string toString() const override;

public:
	Sheep(int x, int y, World* world);
};
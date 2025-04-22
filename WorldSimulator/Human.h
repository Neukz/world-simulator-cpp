#pragma once
#include <unordered_map>
#include "Animal.h"
#include "Direction.h"

class Human : public Animal {
private:
	static const int Strength = 5;
	static const int Initiative = 4;
	static const char Symbol = 'H';
	// Map of arrow keys to Direction
	static const std::unordered_map<int, Direction> KeyToDirection;

	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;
	void move(Direction direction);

public:
	Human(int x, int y, World* world);

	void action() override;
	void collision(Organism* other) override;
};
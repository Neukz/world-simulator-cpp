#pragma once
#include <unordered_map>
#include "Animal.h"
#include "Direction.h"

class Human : public Animal {
private:
	std::string toString() const override;
	void move(Direction direction);

public:
	// Map of arrow keys to Direction
	static const std::unordered_map<int, Direction> KeyToDirection;

	Human(int x, int y, World* world);

	void action() override;
	void collision(Organism* other) override;
};
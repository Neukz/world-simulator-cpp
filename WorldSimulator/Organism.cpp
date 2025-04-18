#include "Organism.h"
#include <iostream>

#pragma region Public methods
Organism::Organism(int strength, int initiative, char symbol, int x, int y, World* world)
	: strength(strength), symbol(symbol), initiative(initiative), position(x, y), world(world) {
	world->addOrganism(this);
}

bool Organism::compareByPosition(Organism* organism1, Organism* organism2) {
	return organism1->getPosition() < organism2->getPosition();
}

void Organism::draw() const {
	std::cout << symbol;
}

void Organism::setPosition(int x, int y) {
	if (x < 0 || y < 0 || x >= world->getWidth() || y >= world->getHeight()) {	// Position out of bounds
		return;
	}
	position.setX(x);
	position.setY(y);
}

int Organism::getStrength() const {
	return strength;
}

int Organism::getInitiative() const {
	return initiative;
}

Position Organism::getPosition() const {
	return position;
}
#pragma endregion
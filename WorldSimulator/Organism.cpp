#include "Organism.h"

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

int Organism::getStrength() const {
	return strength;
}

int Organism::getInitiative() const {
	return initiative;
}

Position Organism::getPosition() const {
	return position;
}
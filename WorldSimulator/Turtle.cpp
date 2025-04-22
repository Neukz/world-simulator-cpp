#include "Turtle.h"

#pragma region Private methods
std::string Turtle::toString() const {
	return "Turtle";
}

Organism* Turtle::createNewInstance(int x, int y) {
	return new Turtle(x, y, world);
}

void Turtle::deflectAttack(Organism* attacker) const {
	Position attackerPrevPosition = attacker->getPrevPosition();
	attacker->setPosition(attackerPrevPosition);
}
#pragma endregion

#pragma region Public methods
Turtle::Turtle(int x, int y, World* world)
	: Animal(Strength, Initiative, Symbol, x, y, world) {}

void Turtle::action() {
	bool shouldStay = (rand() % 100) < 75;	// 75% chance to stay still
	if (shouldStay) {
		return;
	}
	Animal::action();
}

void Turtle::collision(Organism* other) {
	if (typeid(*this) != typeid(*other) && other->getStrength() < 5) {
		return deflectAttack(other);
	}
	Animal::collision(other);
}
#pragma endregion
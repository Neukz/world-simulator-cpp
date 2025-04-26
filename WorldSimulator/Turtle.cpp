#include "Turtle.h"
#include "OrganismFactory.h"

const std::string Turtle::Symbol = u8"🐢";

bool Turtle::registered = [] {
	OrganismFactory::getInstance().registerType("Turtle",
		[](int x, int y, World* world) {
		return new Turtle(x, y, world);
	});
	return true;
}();

#pragma region Private methods
std::string Turtle::toString() const {
	return "Turtle";
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
#pragma once
#include <unordered_map>
#include "Animal.h"

class Human : public Animal {
private:
	enum class Direction {
		Up,
		Down,
		Left,
		Right
	};

	static const int Strength = 5;
	static const int Initiative = 4;
	static const char Symbol = 'H';
	// Map of arrow keys to Direction
	static const std::unordered_map<int, Direction> KeyToDirection;
	static const char MagicalPotionKey = ' ';

	bool magicalPotionActive = false;
	int magicalPotionCooldown = 0;

	std::string toString() const override;
	Organism* createNewInstance(int x, int y) override;
	bool canUseMagicalPotion() const;
	void useMagicalPotion();
	void updateMagicalPotion();

public:
	Human(int x, int y, World* world);

	void action() override;
	void collision(Organism* other) override;
};
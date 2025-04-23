#include "Human.h"
#include "conio.h"

const std::unordered_map<int, Human::Direction> Human::KeyToDirection = {
	{72, Direction::Up},
	{80, Direction::Down},
	{75, Direction::Left},
	{77, Direction::Right}
};

#pragma region Private methods
std::string Human::toString() const {
	return "Human";
}

Organism* Human::createNewInstance(int x, int y) {
	return new Human(x, y, world);
}

bool Human::canUseMagicalPotion() const {
	return !magicalPotionActive && magicalPotionCooldown <= 0;
}

void Human::useMagicalPotion() {
	magicalPotionActive = true;
	magicalPotionCooldown = 0;
	setStrength(10);
	updateMagicalPotion();
	std::cout << "Magical potion used!" << std::endl;
}

void Human::updateMagicalPotion() {
	if (magicalPotionActive) {
		// Decrease strength
		int strength = getStrength();
		if (strength > Strength && magicalPotionCooldown > 0) {
			setStrength(strength - 1);
		}

		// If active and reached 5, deactivate
		if (magicalPotionCooldown == 5) {
			magicalPotionActive = false;
			std::cout << "Magical potion expired!" << std::endl;

			// If smaller than 5, accumulate cooldown
		} else if (magicalPotionCooldown < 5) {
			magicalPotionCooldown++;
		}

		// If inactive, decrease cooldown
	} else {
		magicalPotionCooldown--;
	}
}
#pragma endregion

#pragma region Public methods
Human::Human(int x, int y, World* world)
	: Animal(Strength, Initiative, Symbol, x, y, world) {}

void Human::action() {
	updateMagicalPotion();
	Position position = getPosition();
	int x = position.getX();
	int y = position.getY();
	while (position == getPosition()) {	// Request input until successfully moved
		if (_kbhit()) {
			char key = _getch();

			// Try to activate the special ability
			if (key == MagicalPotionKey && canUseMagicalPotion()) {
				useMagicalPotion();
				continue;
			}

			// Check for arrow keys
			auto direction = KeyToDirection.find(key);
			if (direction != KeyToDirection.end()) {
				int dx = 0, dy = 0;
				switch (direction->second) {
					case Direction::Up:
						dy = -1;
						break;
					case Direction::Down:
						dy = 1;
						break;
					case Direction::Left:
						dx = -1;
						break;
					case Direction::Right:
						dx = 1;
				}
				setPosition(Position(x + dx, y + dy));
			}
		}
	}
	setPrevPosition(position);
}

void Human::collision(Organism* other) {
	if (magicalPotionActive) {

	}
}
#pragma endregion
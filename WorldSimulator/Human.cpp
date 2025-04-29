#include "Human.h"
#include <conio.h>
#include "OrganismFactory.h"

const std::string Human::Symbol = u8"🚶‍♂️";
const std::string Human::Species = "Human";

const std::unordered_map<int, Human::Direction> Human::KeyToDirection = {
	{72, Direction::Up},
	{80, Direction::Down},
	{75, Direction::Left},
	{77, Direction::Right}
};

bool Human::registered = [] {
	OrganismFactory::getInstance().registerType(Species,
		[](int x, int y, World* world) {
		return Human::spawn(x, y, world);
	});
	return true;
}();

Human* Human::instance = nullptr;

#pragma region Private methods
Human::Human(int x, int y, World* world)
	: Animal(Strength, Initiative, Symbol, x, y, world) {}

std::string Human::getSpecies() const {
	return Species;
}

bool Human::canUseMagicalPotion() const {
	return !magicalPotionActive && magicalPotionCooldown <= 0;
}

void Human::useMagicalPotion() {
	setMagicalPotionActive(true);
	magicalPotionCooldown = 0;
	setStrength(10);
	updateMagicalPotion();
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
			std::cout
				<< "\033[33m"
				<< "Magical potion expired!"
				<< "\033[0m"
				<< std::endl;

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
Human* Human::spawn(int x, int y, World* world) {
	if (instance) {
		return nullptr;
	}
	instance = new Human(x, y, world);
	return instance;
}

void Human::deleteInstance() {
	delete instance;
	instance = nullptr;
}

Human* Human::getInstance() {
	return instance;
}

void Human::setMagicalPotionActive(bool active) {
	if (active) {
		std::cout
			<< "\033[33m"
			<< "Magical potion used!"
			<< "\033[0m"
			<< std::endl;
	}

	magicalPotionActive = active;
}

void Human::setMagicalPotionCooldown(int cooldown) {
	magicalPotionCooldown = cooldown;
}

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

std::string Human::serialize() const {
	// Grab all Organism fields and add Human-specific properties
	std::string serialized = Organism::serialize();
	serialized +=
		',' + std::to_string(magicalPotionActive)	// "0" or "1"
		+ ',' + std::to_string(magicalPotionCooldown);

	return serialized;
}
#pragma endregion
#include "Human.h"
#include "conio.h"

const std::unordered_map<int, Direction> Human::KeyToDirection = {
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

void Human::move(Direction direction) {
	int dx = 0, dy = 0;
	switch (direction) {
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
	Position position = getPosition();
	int x = position.getX();
	int y = position.getY();
	setPosition(Position(x + dx, y + dy));
}
#pragma endregion

#pragma region Public methods
Human::Human(int x, int y, World* world)
	: Animal(Strength, Initiative, Symbol, x, y, world) {}

void Human::action() {
	Position position = getPosition();
	while (position == getPosition()) {	// Request input until successfully moved
		if (_kbhit()) {
			char key = _getch();
			auto direction = KeyToDirection.find(key);
			if (direction != KeyToDirection.end()) {
				move(direction->second);
			}
		}
	}
	setPrevPosition(position);
}

void Human::collision(Organism* other) {
	throw std::logic_error("Human::collision not implemented");
}
#pragma endregion
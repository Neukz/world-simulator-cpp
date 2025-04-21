#include "Position.h"
#include "Direction.h"

const Position Position::InvalidPosition = Position(-1, -1);

#pragma region Public methods
Position::Position(int x, int y)
	: x(x), y(y) {}

std::vector<Position> Position::getNeighbors() const {
	std::vector<Position> neighbors = {
		Position(x, y - 1),
		Position(x, y + 1),
		Position(x - 1, y),
		Position(x + 1, y)
	};
	return neighbors;
}

Position Position::getRandomNeighbor(int range) const {
	// Select random direction and shift position by range
	Direction direction = static_cast<Direction>(rand() % 4);
	switch (direction) {
		case Direction::Up:
			return Position(x, y - range);
		case Direction::Down:
			return Position(x, y + range);
		case Direction::Left:
			return Position(x - range, y);
		case Direction::Right:
			return Position(x + range, y);
	}
}

int Position::getX() const {
	return x;
}

int Position::getY() const {
	return y;
}

void Position::setX(int x) {
	this->x = x;
}

void Position::setY(int y) {
	this->y = y;
}

bool Position::operator<(const Position& other) const {
	if (y == other.y) {
		return x < other.x;	// If y is the same, smaller x is smaller position
	}
	return y < other.y;	// Smaller y is smaller position
}

bool Position::operator==(const Position& other) const {
	return x == other.x && y == other.y;
}

bool Position:: operator!=(const Position& other) const {
	return x != other.x || y != other.y;
}

std::ostream& operator<<(std::ostream& out, const Position& position) {
	out << "(" << position.x << "," << position.y << ")";
	return out;
}
#pragma endregion
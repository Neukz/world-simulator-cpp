#include "Position.h"

const Position Position::InvalidPosition = Position(-1, -1);

#pragma region Public methods
Position::Position(int x, int y)
	: x(x), y(y) {}

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

std::vector<Position> Position::getNeighbors(int range) const {
	std::vector<Position> neighbors = {
		Position(x, y - range),
		Position(x, y + range),
		Position(x - range, y),
		Position(x + range, y)
	};
	return neighbors;
}

Position Position::getRandomNeighbor(int range) const {
	std::vector<Position> neighbors = getNeighbors(range);
	Position randomNeighbor = neighbors[rand() % neighbors.size()];
	return randomNeighbor;
}

bool Position::operator<(const Position& other) const {
	if (this->y == other.y) {
		return this->x < other.x;	// If y is the same, smaller x is smaller position
	}
	return this->y < other.y;	// Smaller y is smaller position
}

bool Position::operator==(const Position& other) const {
	return this->x == other.x && this->y == other.y;
}

bool Position:: operator!=(const Position& other) const {
	return this->x != other.x || this->y != other.y;
}

std::ostream& operator<<(std::ostream& out, const Position& position) {
	out << "(" << position.x << "," << position.y << ")";
	return out;
}
#pragma endregion
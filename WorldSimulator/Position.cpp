#include "Position.h"

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

bool Position::operator<(const Position& other) const {
	if (y == other.y) {
		return x < other.x;	// If y is the same, smaller x is smaller position
	}
	return y < other.y;	// Smaller y is smaller position
}

bool Position::operator==(const Position& other) const {
	return x == other.x && y == other.y;
}
#pragma endregion
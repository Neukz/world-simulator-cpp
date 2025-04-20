#pragma once
#include <iostream>

class Position {
private:
	int x;
	int y;

public:
	static const Position InvalidPosition;

	Position(int x, int y);

	Position getRandomNeighbor(int range) const;

	int getX() const;
	int getY() const;

	void setX(int x);
	void setY(int y);

	bool operator<(const Position& other) const;
	bool operator==(const Position& other) const;
	friend std::ostream& operator<<(std::ostream& out, const Position& position);
};
#pragma once
#include <iostream>
#include <vector>

class Position {
private:
	int x;
	int y;

public:
	static const Position InvalidPosition;

	Position(int x, int y);

	int getX() const;
	int getY() const;

	void setX(int x);
	void setY(int y);

	std::vector<Position> getNeighbors(int range = 1) const;
	Position getRandomNeighbor(int range = 1) const;

	bool operator<(const Position& other) const;
	bool operator==(const Position& other) const;
	bool operator!=(const Position& other) const;
	friend std::ostream& operator<<(std::ostream& out, const Position& position);
};
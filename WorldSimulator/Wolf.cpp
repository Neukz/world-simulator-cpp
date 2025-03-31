#include "Wolf.h"

const int WOLF_STRENGTH = 9;
const int WOLF_INITIATIVE = 5;
const char WOLF_SYMBOL = 'W';

Wolf::Wolf(int x, int y, World* world)
	: Animal(WOLF_STRENGTH, WOLF_INITIATIVE, WOLF_SYMBOL, x, y, world) {}
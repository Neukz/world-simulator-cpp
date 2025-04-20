#include <iostream>
#include <conio.h>
#include "World.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"

int main() {
	World* world = new World(20, 10);
	Wolf* wolf1 = new Wolf(10, 6, world);
	Sheep* sheep1 = new Sheep(10, 5, world);
	Sheep* sheep2 = new Sheep(11, 5, world);
	Fox* fox1 = new Fox(15, 5, world);
	Turtle* turtle1 = new Turtle(12, 7, world);
	Antelope* antelope1 = new Antelope(2, 8, world);
	Antelope* antelope2 = new Antelope(3, 9, world);

	try {
		world->drawWorld();
		while (true) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 13) {
					world->makeTurn();
					world->drawWorld();
				}
			}
		}
	} catch (const std::logic_error& err) {
		std::cout << err.what() << std::endl;
	}

	delete world;
}
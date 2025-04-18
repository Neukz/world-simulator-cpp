#include <iostream>
#include <conio.h>
#include "World.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"

int main() {
	std::setlocale(LC_ALL, "en_US.UTF-8");	// Support unicode characters
	srand(time(nullptr));

	World* world = new World(50, 20);
	Wolf* wolf1 = new Wolf(0, 0, world);
	Sheep* sheep1 = new Sheep(1, 1, world);
	Sheep* sheep2 = new Sheep(2, 0, world);
	Sheep* sheep3 = new Sheep(3, 1, world);
	Fox* fox1 = new Fox(2, 2, world);

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
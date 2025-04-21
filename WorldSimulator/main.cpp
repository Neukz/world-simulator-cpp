#include <conio.h>
#include "World.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "SowThistle.h"
#include "Guarana.h"
#include "Belladonna.h"

int main() {
	World* world = new World(20, 10);
	world->populate({
		// Animals
		new Wolf(10, 6, world),
		new Sheep(10, 5, world),
		new Sheep(11, 5, world),
		new Fox(15, 5, world),
		new Turtle(12, 7, world),
		new Antelope(2, 8, world),
		new Antelope(3, 9, world),

		// Plants
		new Grass(5, 5, world),
		new SowThistle(5, 8, world),
		new Guarana(13, 3, world),
		new Belladonna(7, 6, world)
	});

	try {
		world->drawWorld();
		while (true) {
			if (_kbhit()) {
				char key = _getch();
				if (key == '\\') {
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
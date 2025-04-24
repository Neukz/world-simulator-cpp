#include <conio.h>
#include "Human.h"
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
#include "SosnowskysHogweed.h"

int main() {
	World* world = new World(20, 10);
	world->populate({
		// Animals
		new Human(10, 8, world),
		new Wolf(13, 3, world),
		new Wolf(18, 2, world),
		new Sheep(8, 2, world),
		new Sheep(9, 3, world),
		new Fox(15, 5, world),
		new Fox(11, 5, world),
		new Turtle(12, 7, world),
		new Turtle(14, 7, world),
		new Antelope(2, 8, world),
		new Antelope(3, 9, world),

		// Plants
		new Grass(9, 5, world),
		new SowThistle(5, 8, world),
		new Guarana(2, 6, world),
		new Belladonna(7, 6, world),
		new SosnowskysHogweed(10, 5, world)
	});

	try {
		world->drawWorld();
		while (true) {
			if (_kbhit()) {
				char key = _getch();
				switch (key) {
					case 'n':
						world->makeTurn();
						world->drawWorld();
						break;
					case 's':
						world->saveWorld();
						break;
					case 'l':
						world->loadWorld();
						world->drawWorld();
				}
			}
		}
	} catch (const std::logic_error& err) {
		std::cout << err.what() << std::endl;
	}

	delete world;
}
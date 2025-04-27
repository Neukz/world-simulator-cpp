#pragma once
#include "Plant.h"

class SosnowskysHogweed : public Plant {
private:
	static const int Strength = 10;
	static const std::string Symbol;
	static const std::string Species;

	static bool registered;

	std::string getSpecies() const override;
	void killNeighboringAnimals();

public:
	SosnowskysHogweed(int x, int y, World* world);

	void action() override;
	void collision(Organism* other) override;
};
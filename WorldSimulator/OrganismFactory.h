#pragma once
#include <unordered_map>
#include <string>
#include <functional>
#include "Organism.h"

class OrganismFactory {
private:
    using Creator = std::function<Organism*(int x, int y, World* world)>;

	std::unordered_map<std::string, Creator> creators;

    // Singleton pattern
    OrganismFactory() = default;
    OrganismFactory(const OrganismFactory&) = delete;
    OrganismFactory& operator=(const OrganismFactory&) = delete;

public:
    static OrganismFactory& getInstance();

    void registerType(const std::string& name, Creator creator);
    Organism* create(const std::string& name, int x, int y, World* world) const;
};
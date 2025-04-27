#include "OrganismFactory.h"

#pragma region Public methods
OrganismFactory& OrganismFactory::getInstance() {
    static OrganismFactory instance;
    return instance;
}

std::vector<std::string> OrganismFactory::getRegisteredTypes() const {
    std::vector<std::string> types;
    for (const auto& creator : creators) {
        types.push_back(creator.first);
    }
    return types;
}

void OrganismFactory::registerType(const std::string& name, Creator creator) {
    creators[name] = creator;
}

Organism* OrganismFactory::create(const std::string& name, int x, int y, World* world) const {
    auto creator = creators.find(name);
    if (creator != creators.end()) {
        return creator->second(x, y, world);
    }
    return nullptr;
}
#pragma endregion
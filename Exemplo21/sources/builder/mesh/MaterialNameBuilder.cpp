#include "../../headers/builder/mesh/MaterialNameBuilder.h"

MaterialNameBuilder::MaterialNameBuilder(MeshMediator* mediator) {
    this->mediator = mediator;
}

MaterialNameBuilder::~MaterialNameBuilder() {}

void MaterialNameBuilder::process(stringstream& line) {
    string name;
    line >> name;
    while (!line.eof()) {
        string temp;
        line >> temp;
        name += " " + temp;
    }

    this->mediator->callbackMaterialName(name);
}

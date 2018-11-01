#include "../../headers/builder/mesh/MaterialFileBuilder.h"

MaterialFileBuilder::MaterialFileBuilder(MeshMediator* mediator) {
    this->mediator = mediator;
}

MaterialFileBuilder::~MaterialFileBuilder() {}

void MaterialFileBuilder::process(stringstream& line) {
    string name;
    line >> name;
    while (!line.eof()) {
        string temp;
        line >> temp;
        name += " " + temp;
    }

    this->mediator->callbackMaterialFile(name);
}

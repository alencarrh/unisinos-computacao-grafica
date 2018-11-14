#include "../../headers/builder/material/NewMaterialBuilder.h"

NewMaterialBuilder::NewMaterialBuilder(MaterialMediator* mediator) {
    this->mediator = mediator;
}

NewMaterialBuilder::~NewMaterialBuilder() {}

void NewMaterialBuilder::process(stringstream& line) {
    string name;
    line >> name;
    while (!line.eof()) {
        string temp;
        line >> temp;
        name += " " + temp;
    }

    this->mediator->callbackNewMaterial(name);
}

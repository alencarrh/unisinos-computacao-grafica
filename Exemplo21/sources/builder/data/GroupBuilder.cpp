#include "../../headers/builder/data/GroupBuilder.h"

GroupBuilder::GroupBuilder(MeshMediator* mediator) {
    this->mediator = mediator;
}

GroupBuilder::~GroupBuilder() {}

void GroupBuilder::process(stringstream& line) {
    string name;
    line >> name;
    while (!line.eof()) {
        string temp;
        line >> temp;
        name += " " + temp;
    }

    this->mediator->callbackGroup(name);
}

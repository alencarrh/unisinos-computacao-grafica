#include "../../headers/builder/material/NShininessBuilder.h"

NShininessBuilder::NShininessBuilder(MaterialMediator* mediator) {
    this->mediator = mediator;
}

NShininessBuilder::~NShininessBuilder() {}

void NShininessBuilder::process(stringstream& line) {
    string stringValue;
    line >> stringValue;
    this->mediator->callbackNShinness(atof(stringValue.c_str()));
}

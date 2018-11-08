#include "../../headers/builder/material/KAmbientBuilder.h"

KAmbientBuilder::KAmbientBuilder(MaterialMediator* mediator) {
    this->mediator = mediator;
}

KAmbientBuilder::~KAmbientBuilder() {}

void KAmbientBuilder::process(stringstream& line) {
    float r, g, b;
    line >> r >> g >> b;
    this->mediator->callbackKAmbient(new glm::vec3(r, g, b));
}

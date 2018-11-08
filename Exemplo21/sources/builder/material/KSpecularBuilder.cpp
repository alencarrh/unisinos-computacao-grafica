#include "../../headers/builder/material/KSpecularBuilder.h"

KSpecularBuilder::KSpecularBuilder(MaterialMediator* mediator) {
    this->mediator = mediator;
}

KSpecularBuilder::~KSpecularBuilder() {}

void KSpecularBuilder::process(stringstream& line) {
    float r, g, b;
    line >> r >> g >> b;
    this->mediator->callbackKSpecular(new glm::vec3(r, g, b));
}

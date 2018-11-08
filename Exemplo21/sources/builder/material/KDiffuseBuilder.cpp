#include "../../headers/builder/material/KDiffuseBuilder.h"

KDiffuseBuilder::KDiffuseBuilder(MaterialMediator* mediator) {
    this->mediator = mediator;
}

KDiffuseBuilder::~KDiffuseBuilder() {}

void KDiffuseBuilder::process(stringstream& line) {
    float r, g, b;
    line >> r >> g >> b;
    this->mediator->callbackKDiffusse(new glm::vec3(r, g, b));
}

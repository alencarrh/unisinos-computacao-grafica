#include "../../../headers/builder/values/NormalBuilder.h"


NormalBuilder::NormalBuilder(MeshMediator* mediator) {
    this->mediator = mediator;
}

NormalBuilder::~NormalBuilder() {}

void NormalBuilder::process(stringstream& line) {

    float x, y, z;
    line >> x >> y >> z;

    this->mediator->callbackNormal(new glm::vec3(x, y, z));
}

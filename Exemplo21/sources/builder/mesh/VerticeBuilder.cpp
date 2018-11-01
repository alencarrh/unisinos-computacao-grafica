#include "../../../headers/builder/mesh/VerticeBuilder.h"


VerticeBuilder::VerticeBuilder(MeshMediator* mediator) {
    this->mediator = mediator;
}

VerticeBuilder::~VerticeBuilder() {}

void VerticeBuilder::process(stringstream& line) {
    float x, y, z;
    line >> x >> y >> z;

    this->mediator->callbackVertice(new glm::vec3(x, y, z));
}

#include "../../headers/builder/VerticeBuilder.h"

void VerticeBuilder::process(stringstream& line) {
    float x, y, z;
    line >> x >> y >> z;
    this->vertices.push_back(new glm::vec3(x, y, z));
}

vector<glm::vec3*>& VerticeBuilder::build() {
    return this->vertices;
}

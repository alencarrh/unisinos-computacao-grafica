#include "../../headers/builder/KdBuilder.h"

void KdBuilder::process(stringstream& line) {
    float r, g, b;
    line >> r >> g >> b;
    kd.push_back(new glm::vec3(r, g, b));
}

vector<glm::vec3*>& KdBuilder::build() {
    //TODO limpar lista aqui já que está classe está static
    return kd;
}

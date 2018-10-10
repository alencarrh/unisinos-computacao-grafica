#include "../../headers/builder/KDiffuseBuilder.h"

void KDiffuseBuilder::process(stringstream& line) {
    float r, g, b;
    line >> r >> g >> b;
    kd.push_back(new glm::vec3(r, g, b));
}

vector<glm::vec3*>& KDiffuseBuilder::build() {
    //TODO limpar lista aqui já que está classe está static
    return kd;
}

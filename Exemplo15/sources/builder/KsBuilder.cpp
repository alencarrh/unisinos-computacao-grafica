#include "../../headers/builder/KsBuilder.h"

void KsBuilder::process(stringstream& line) {
    float r, g, b;
    line >> r >> g >> b;
    ks.push_back(new glm::vec3(r, g, b));
}

vector<glm::vec3*>& KsBuilder::build() {
    //TODO limpar lista aqui já que está classe está static
    return ks;
}

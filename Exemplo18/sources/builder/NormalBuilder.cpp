#include "../../headers/builder/NormalBuilder.h"

void NormalBuilder::process(stringstream& line) {

    float x, y, z;
    line >> x >> y >> z;

    normais.push_back(new glm::vec3(x, y, z));
}

vector<glm::vec3*>& NormalBuilder::build() {
    //TODO limpar lista aqui já que está classe está static
    return normais;
}

#include "../../headers/builder/VerticeBuilder.h"

void VerticeBuilder::process(stringstream& line) {
    float x, y, z;
    line >> x >> y >> z;
    vertices.push_back(new glm::vec3(x, y, z));
}

vector<glm::vec3*>& VerticeBuilder::build() {
    //TODO limpar lista aqui já que está classe está static
    return vertices;
}

#include "../../../headers/builder/light/KSpecularBuilder.h"

void KSpecularBuilder::process(stringstream& line) {
    float r, g, b;
    line >> r >> g >> b;
    ks = new glm::vec3(r, g, b);
}

glm::vec3* KSpecularBuilder::build() {
    return ks;
}

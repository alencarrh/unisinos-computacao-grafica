#include "../../../headers/builder/light/KDiffuseBuilder.h"

void KDiffuseBuilder::process(stringstream& line) {
    float r, g, b;
    line >> r >> g >> b;
    kd = new glm::vec3(r, g, b);
}

glm::vec3* KDiffuseBuilder::build() {
    return kd;
}

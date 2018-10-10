#include "../../../headers/builder/light/KAmbientBuilder.h"

void KAmbientBuilder::process(stringstream& line) {
    float r, g, b;
    line >> r >> g >> b;
    ka = new glm::vec3(r, g, b);
}

glm::vec3* KAmbientBuilder::build() {
    return ka;
}

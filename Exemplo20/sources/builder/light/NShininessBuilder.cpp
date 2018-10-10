#include "../../../headers/builder/light/NShininessBuilder.h"

void NShininessBuilder::process(stringstream& line) {
    string stringValue;
    line >> stringValue;
    ns = atof(stringValue.c_str());
}

float NShininessBuilder::build() {
    return ns;
}

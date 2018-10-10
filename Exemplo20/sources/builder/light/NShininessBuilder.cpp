#include "../../../headers/builder/light/NShininessBuilder.h"

void NShininessBuiler::process(stringstream& line) {
    string stringValue;
    line >> stringValue;
    ns = atof(stringValue.c_str());
}

float NShininessBuiler::build() {
    return ns;
}

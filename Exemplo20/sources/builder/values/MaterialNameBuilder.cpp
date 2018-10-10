#include "../../../headers/builder/values/MaterialNameBuilder.h"

void MaterialNameBuilder::process(std::stringstream& line) {
    line >> name;
}

string MaterialNameBuilder::build() {
    return name;
}

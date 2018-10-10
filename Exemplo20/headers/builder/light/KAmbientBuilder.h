#ifndef KAMBIENT_BUILDER_H
#define KAMBIENT_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>

using namespace std;
static glm::vec3* ka;

class KAmbientBuilder {

public:
    static void process(stringstream& line);
    static glm::vec3* build();
};
#endif

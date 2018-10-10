#ifndef KDIFFUSE_BUILDER_H
#define KDIFFUSE_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>

using namespace std;
static glm::vec3* kd;

class KDiffuseBuilder {

public:
    static void process(stringstream& line);
    static glm::vec3* build();

};
#endif

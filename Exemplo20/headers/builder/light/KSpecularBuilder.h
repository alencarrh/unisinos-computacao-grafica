#ifndef KSPECULAR_BUILDER_H
#define KSPECULAR_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>

using namespace std;
static glm::vec3* ks;

class KSpecularBuilder {

public:
    static void process(stringstream& line);
    static glm::vec3* build();

};
#endif

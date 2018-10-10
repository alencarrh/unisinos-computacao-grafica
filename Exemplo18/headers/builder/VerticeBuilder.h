#ifndef VERTICE_BUILDER_H
#define VERTICE_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>

using namespace std;

static vector<glm::vec3*> vertices;

class VerticeBuilder {

public:
    static void process(stringstream& line);
    static vector<glm::vec3*>& build();

};
#endif

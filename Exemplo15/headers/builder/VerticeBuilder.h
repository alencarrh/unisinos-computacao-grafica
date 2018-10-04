#ifndef VERTICE_BUILDER_H
#define VERTICE_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>

using namespace std;

class VerticeBuilder {

private:
    vector<glm::vec3*> vertices;

public:
    void process(std::stringstream& line);
    vector<glm::vec3*>& build();

};
#endif

#ifndef NORMAL_BUILDER_H
#define NORMAL_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>

using namespace std;

class NormalBuilder {

private:
    vector<glm::vec3*> normais;

public:
    void process(std::stringstream& line);
    vector<glm::vec3*>& build();
};

#endif

#ifndef NORMAL_BUILDER_H
#define NORMAL_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>

using namespace std;

static vector<glm::vec3*> normais;

class NormalBuilder {

public:
	static void process(stringstream& line);
    static vector<glm::vec3*>& build();

};

#endif

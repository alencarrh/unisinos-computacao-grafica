#ifndef NORMAL_BUILDER_H
#define NORMAL_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>
#include "../MeshMediator.h"

using namespace std;

class NormalBuilder {
private:
	MeshMediator* mediator;

public:
    NormalBuilder(MeshMediator* mediator);
    ~NormalBuilder();
    void process(stringstream& line);
};

#endif

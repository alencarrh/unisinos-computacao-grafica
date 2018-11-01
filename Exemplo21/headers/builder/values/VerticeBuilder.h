#ifndef VERTICE_BUILDER_H
#define VERTICE_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>
#include "../MeshMediator.h"

using namespace std;

class VerticeBuilder {
private:
	MeshMediator* mediator;

public:
    VerticeBuilder(MeshMediator* mediator);
    ~VerticeBuilder();
    void process(stringstream& line);
};
#endif

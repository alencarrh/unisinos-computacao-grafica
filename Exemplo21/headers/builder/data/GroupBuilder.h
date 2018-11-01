#ifndef GROUP_BUILDER_H
#define GROUP_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>
#include "../MeshMediator.h"

using namespace std;

class GroupBuilder {
private:
	MeshMediator* mediator;

public:
	GroupBuilder(MeshMediator* mediator);
	~GroupBuilder();
	void process(stringstream& line);
};

#endif

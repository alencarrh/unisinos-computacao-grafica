#ifndef MATERIAL_NAME_BUILDER_H
#define MATERIAL_NAME_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>
#include "../MeshMediator.h"

using namespace std;

class MaterialNameBuilder {
private:
	MeshMediator* mediator;

public:
	MaterialNameBuilder(MeshMediator* mediator);
	~MaterialNameBuilder();
	void process(stringstream& line);
};

#endif

#ifndef MATERIAL_FILE_BUILDER_H
#define MATERIAL_FILE_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>
#include "../MeshMediator.h"

using namespace std;

class MaterialFileBuilder {
private:
	MeshMediator* mediator;

public:
	MaterialFileBuilder(MeshMediator* mediator);
	~MaterialFileBuilder();
	void process(stringstream& line);
};

#endif

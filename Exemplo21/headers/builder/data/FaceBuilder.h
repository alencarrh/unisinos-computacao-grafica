#ifndef FACE_BUILDER_H
#define FACE_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>
#include "../MeshMediator.h"

using namespace std;

class FaceBuilder {
private:
	MeshMediator* mediator;

public:
    FaceBuilder(MeshMediator* mediator);
    ~FaceBuilder();
    void process(stringstream& line);
};

#endif

#ifndef TEXTURE_BUILDER_H
#define TEXTURE_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>
#include "../MeshMediator.h"

using namespace std;

class TextureBuilder {
private:
	MeshMediator* mediator;

public:
    TextureBuilder(MeshMediator* mediator);
    ~TextureBuilder();
    void process(stringstream& line);
};
#endif
